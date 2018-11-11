#include "TrackZVertexGrouping.h"

// #include <iostream>
// #include <cmath>
// #include <functional>
// #include <algorithm>


#include <lcio.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/Track.h>
#include <IMPL/ReconstructedParticleImpl.h>
#include <IMPL/VertexImpl.h>

// #include <UTIL/BitField64.h>
// #include <UTIL/ILDConf.h>
#include <UTIL/Operators.h>
#include <UTIL/LCTOOLS.h>

// ----- include for verbosity dependend logging ---------
#include "marlin/VerbosityLevels.h"

#include <marlin/AIDAProcessor.h>
#include <marlin/Global.h>

#include <AIDA/IHistogramFactory.h>

//---- ROOT -----
#include "TH1F.h"

using namespace lcio ;
using namespace marlin ;

TrackZVertexGrouping aTrackZVertexGrouping ;

//=========================================================================================

/// helper struct for clustering tracks

namespace {

       struct TrackGroup {

	      std::list<Track*> tracks{} ;
	      double z0=0. ;
	      double z0error=0. ;
	    
	      TrackGroup( Track* trk){

		     tracks.push_back( trk ) ;
		     z0 = trk->getZ0() ;
		     z0error = (trk->getCovMatrix()[ 9 ]) ; // 9 should be index of sigma_z0 (square root is not used since it has to be squared later)!!
	      }

	      // merge other group into this - after this the other group is emtpy
	      void merge( TrackGroup& other ){
		     tracks.merge( other.tracks ) ;

		     //FIXME: re-compute the Z0 significance - can this be made more efficient ?
		     int ntrk = 0 ;
		     double z0Mean = 0.;
		     double z0errorMean = 0.;

		     for(auto trk : tracks ){
			      z0Mean += ( trk->getZ0() /( trk->getCovMatrix()[ 9 ] )) ;
			      z0errorMean += (1/(  trk->getCovMatrix()[ 9 ] )) ;
			    ++ntrk;
		     }
		     z0 =  z0Mean / z0errorMean;
		     z0error = 1 / z0errorMean ;
	      }
       } ;

       std::ostream& operator<<( std::ostream& os, const TrackGroup& grp ){
  
	      os << " group with " << grp.tracks.size() << " elements - z0 = " << grp.z0  << std::endl ;
	      for( auto trk : grp.tracks ){
		     os  << "       - trk: " << lcshort( trk ) << std::endl ; 
	      }
	      return os ;
       }
}
//=========================================================================================

TrackZVertexGrouping::TrackZVertexGrouping() : Processor("TrackZVertexGrouping") {

       // modify processor description
       _description = "TrackZVertexGrouping: group tracks based on their Z0 significance";

       // register steering parameters: name, description, class-variable, default value
       registerInputCollection( LCIO::TRACK,
				"TrackCollection" , 
				"Name of the Track input collection"  ,
				_colNameTracks,
				std::string("CutPassedTracks")
				);
       
       registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
				 "PFOs" , 
				 "Name of the ReconstructedParticle output collection"  ,
				 _colNamePFOs ,
				 std::string("PandoraPFOs")
				 );




        registerOutputCollection( LCIO::RECONSTRUCTEDPARTICLE,
				 "TrackGroupPFOs" , 
				 "Name of the ReconstructedParticle output collection"  ,
				 _colNameTrkGroupPFOs ,
				 std::string("TrackGroupPFOs")
				 );
  
       registerOutputCollection( LCIO::VERTEX,
				 "TrackGroupVertices",
				 "Name of the Vertex output collection"  ,
				 _colNameTrkGroupVertices ,
				 std::string("TrackGroupVertices")
				 );
  
       registerProcessorParameter("Z0SignificanceCut",
				  "Cut for merging track groups in Z0 significance",
				  _z0SignificanceCut,
				  float(1.7) );
  
}



void TrackZVertexGrouping::init() { 

       streamlog_out(DEBUG) << "   init called  " << std::endl ;

       // usually a good idea to
       printParameters() ;

       _nRun = 0 ;
       _nEvt = 0 ;

}


void TrackZVertexGrouping::processRunHeader( LCRunHeader* ) {

       _nRun++ ;
} 



void TrackZVertexGrouping::processEvent( LCEvent * evt ) { 

       streamlog_out(DEBUG2) << "   process event: " << evt->getEventNumber() 
			     << "   in run:  " << evt->getRunNumber() << std::endl ;

       // get the Track collection from the event if it exists
       LCCollection* colTrk = nullptr ;
   
       try{
	      colTrk = evt->getCollection( _colNameTracks ) ;
       }
       catch(lcio::Exception){
	      streamlog_out( DEBUG6 ) << " collection " << _colNameTracks
				      << " not found in event - nothing to do ... " << std::endl ;
       }

       if( colTrk->getTypeName() != LCIO::TRACK ) {

	      streamlog_out( ERROR ) << " collection " << _colNameTracks
				     << " not of type LCIO::TRACK " << std::endl ;

	      colTrk = nullptr ;
       }
    
       if( colTrk == nullptr )
	      return ;
      
    


       int nTrkTotal = colTrk->getNumberOfElements()  ;
    
    
       std::vector<Track*> tracks ;
       tracks.reserve( nTrkTotal ) ;

       // copy all relevant tracks to a vector first
       for(int i=0; i< nTrkTotal ; ++i){ 
    
	      Track* trk = dynamic_cast<Track*>(  colTrk->getElementAt( i ) ) ;

	      // could apply track quality criteria here ...
	      if( true ){

		     tracks.push_back( trk ) ;
	      }
       }
      
  
       // ========================================================================================
       // list of groups - initially all tracks
       std::list< TrackGroup > groups ;
       for( auto trk : tracks ){
	      groups.emplace_back( TrackGroup( trk ) ) ;
       }

       // sort wrt ascending z0 significance
       // groups.sort( [](TrackGroup& a, TrackGroup& b) {return a.z0Significance < b.z0Significance ; } ) ;

       //=========================================================================================
    
       bool keepGoing = true ;
  
       while( keepGoing ) {

	      // loop over all neighboring pairs of groups:
	      double deltaMin = 1.e9 ;
	      std::list< TrackGroup >::iterator smallestDistGroup =  groups.end() ;
    
	      auto gEnd = groups.end() ;
	      std::advance( gEnd , - 1 ) ;  // end loop one before the last 
	      for( auto gIt = groups.begin() ; gIt != gEnd ; ++gIt ) {
		     for( auto jIt = groups.begin() ; jIt != gEnd ; ++jIt ) {
			    //  auto nextGrp = gIt ;
			    // std::advance( nextGrp, 1 ) ;
			    if(gIt != jIt){
				   double deltaZ0Sig = std::fabs( (gIt->z0 - jIt->z0)/(sqrt(gIt->z0error + jIt->z0error)) ) ;
			    
				   if( deltaZ0Sig < deltaMin ) {
					  deltaMin = deltaZ0Sig ;
					  smallestDistGroup = gIt ;
				   }
			    }
		     }
	      }
	      if( smallestDistGroup == groups.end() ){
		     keepGoing = false;
		     break ;
	      }

	      // now merge the two groups w/ smallest difference in z0Sigma
	      if(  deltaMin < _z0SignificanceCut ){
    
		     auto nextGrp = smallestDistGroup ;
		     std::advance( nextGrp, 1 ) ;
      
		     smallestDistGroup->merge( *nextGrp ) ;
      
		     // and remove the empty group from the list
		     groups.erase( nextGrp ) ;

	      } else { // we are done
 
		     keepGoing = false;
		     break ;
	      }

       }

       //=========================================================================================
       // some debug printout:
  
       streamlog_out( DEBUG3 ) << " ==============================================================  " << std::endl
			       << "      found " << groups.size() << " groups " << std::endl ;
       for(auto grp : groups ) {

	      streamlog_out( DEBUG3 ) << grp << std::endl ;
       }



       // create output collections:

       LCCollectionVec* pfos     = new LCCollectionVec( LCIO::RECONSTRUCTEDPARTICLE ) ;
       LCCollectionVec* vertices = new LCCollectionVec( LCIO::VERTEX ) ;

       evt->addCollection( pfos,     _colNameTrkGroupPFOs ) ;
       evt->addCollection( vertices, _colNameTrkGroupVertices ) ;

       LCCollection* pfoCol = nullptr ;
   
       try{
	     pfoCol  = evt->getCollection( _colNamePFOs  ) ;
       }
       catch(lcio::Exception){
	      streamlog_out( DEBUG6 ) << " collection " << _colNamePFOs
				      << " not found in event - nothing to do ... " << std::endl ;
	      return;
       }


       for(auto grp : groups ) {

	      IMPL::ReconstructedParticleImpl* pfo = new IMPL::ReconstructedParticleImpl ;

	      //FIXME: simplistic mean of z0
	      double z0Mean = 0. ;
	      double z0 = 0. ;
	      double z0errorMean = 0. ;

	      int nTrk=0;
	      for(auto trk : grp.tracks){
		    
		     pfo->addTrack( trk ) ;
		     
		     EVENT::ReconstructedParticle *particle = findPfo(trk,  pfoCol);
		     if(nullptr != particle) {
      		     pfo->addParticle(particle);
		     }
		     z0Mean += ( trk->getZ0() /( trk->getCovMatrix()[ 9 ] )) ;
		     z0errorMean += (1/(  trk->getCovMatrix()[ 9 ] )) ;
		     ++nTrk ;
	      }
	      z0= z0Mean/z0errorMean ;
    
	      pfos->addElement( pfo ) ;

	      IMPL::VertexImpl* vtx = new IMPL::VertexImpl ;
	      vtx->setAssociatedParticle( pfo ) ;
	      vtx->setPosition( 0., 0., z0 ) ;
	      //FIXME: compute a meaningful covariance/error for the position
    
	      vertices->addElement( vtx ) ;
    
       }    

       //=========================================================================================
       _nEvt ++ ;

}



void TrackZVertexGrouping::check( LCEvent* /*evt*/) {

       streamlog_out( DEBUG ) << " --- check called ! " << std::endl ; 


       // create some histograms with beta vs momentum for charged particles
  
       if( isFirstEvent() ){

	      // this creates a directory for this processor ....
	      AIDAProcessor::histogramFactory( this ) ;

	      // _h.resize(5) ;
	      // int nBins = 100 ;
	      // _h[0] = new TH2F( "hbetaFirstHitsChrg", "beta vs momentum - first hit - charged",    nBins, .1 , 10., nBins, 0.93 , 1.03 ) ; 
	      // _h[1] = new TH2F( "hbetaCloseHitsChrg", "beta vs momentum - closest hits - charged", nBins, .1 , 10., nBins, 0.93 , 1.03 ) ; 

	      // _h[2] = new TH2F( "hbetaFirstHitsNeut", "beta vs momentum - first hit - neutral",    nBins, .1 , 10., nBins, 0.93 , 1.03 ) ; 
	      // _h[3] = new TH2F( "hbetaCloseHitsNeut", "beta vs momentum - closest hits - neutral", nBins, .1 , 10., nBins, 0.93 , 1.03 ) ; 

	      // _h[4] = new TH2F( "hbetaLastTrkHit",    "beta vs momentum - last tracker hit", nBins, .1 , 10., nBins, 0.93 , 1.03 ) ; 

       }
  
}

void TrackZVertexGrouping::end(){ 


       streamlog_out(MESSAGE) << "TrackZVertexGrouping::end()  " << name() 
			      << " processed " << _nEvt << " events in " << _nRun << " runs "
			      << std::endl ;

}

EVENT::ReconstructedParticle* TrackZVertexGrouping::findPfo(const EVENT::Track *const groupTrack, const EVENT::LCCollection *const pfoCollection) {

  for (unsigned int e=0 ; e < pfoCollection->getNumberOfElements() ; e++) {

    EVENT::ReconstructedParticle *pPfo = static_cast<EVENT::ReconstructedParticle*>(pfoCollection->getElementAt(e));
    auto tracks = pPfo->getTracks();

    auto findIter = std::find(tracks.begin(), tracks.end(), groupTrack);

    if (tracks.end() != findIter) {
      return pPfo;
    }
  }
  return nullptr;
}


//*******************************************************************************************************

