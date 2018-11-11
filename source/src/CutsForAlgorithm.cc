#include "CutsForAlgorithm.h"

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
#include <UTIL/LCRelationNavigator.h>
// ----- include for verbosity dependend logging ---------
#include "marlin/VerbosityLevels.h"

#include <marlin/AIDAProcessor.h>
#include <marlin/Global.h>

#include <AIDA/IHistogramFactory.h>

//---- ROOT -----
#include "TH1F.h"

using namespace lcio ;
using namespace marlin ;

CutsForAlgorithm  aCutsForAlgorithm ;

//=========================================================================================


CutsForAlgorithm::CutsForAlgorithm() : Processor("CutsForAlgorithm") {

       // modify processor description
       _description = "CutsForAlgorithm : cuts for track vertxing group input tracks";

       // register steering parameters: name, description, class-variable, default value
       registerInputCollection( LCIO::TRACK,
				"TrackCollection" , 
				"Name of the Track input collection"  ,
				_colNameTracks,
				std::string("MarlinTrkTracks")
				);


       registerInputCollection( LCIO::MCPARTICLE,
				"InputMCParticleCollection", 
				"Name of the MC particle collection",
				_inputMCsCollection,
				std::string("MCParticlesSkimmed") );

       registerInputCollection( LCIO::LCRELATION,
				"InputMCTruthMarlinTrkTracksLink",
				"Relation between MC and tracks",
				_mctrkRelation,
				std::string("MCTruthMarlinTrkTracksLink"));

       registerOutputCollection( LCIO::TRACK,
				 "CutPassedTracks" , 
				 "Name of the track output collection"  ,
				 _colNameCutPassedTrks ,
				 std::string("CutPassedTracks")
				 );

       registerOutputCollection( LCIO::TRACK,
				 "HighestD0Track" , 
				 "Name of the highest d0 track output collection"  ,
				 _colNameHighestD0Trks ,
				 std::string("highestD0Tracks")
				 );

       registerProcessorParameter("Z0cut",
				  "Z0 cut for algorithm",
				  _z0cut,
				  float(15) );
   
       registerProcessorParameter("D0cut",
				  "D0 cut for algorithm",
				  _d0cut,
				  float(0.2) );
  
}

  
      void CutsForAlgorithm::init() { 

       streamlog_out(DEBUG) << "   init called  " << std::endl ;

       // usually a good idea to
       printParameters() ;

       _nRun = 0 ;
       _nEvt = 0 ;

}


void CutsForAlgorithm::processRunHeader( LCRunHeader* ) {

       _nRun++ ;
} 

void CutsForAlgorithm::processEvent( LCEvent * evt ) { 

       
       streamlog_out(DEBUG) << "   processEvent called, event  " << evt->getEventNumber() << std::endl ;

       LCCollection* colmcp = evt->getCollection(_inputMCsCollection);
       LCCollection* coltrk = evt->getCollection(_colNameTracks);
       LCRelationNavigator* rel= new LCRelationNavigator( evt->getCollection( _mctrkRelation ) );
       
       if (!colmcp) {
	      streamlog_out(ERROR) << "   collection  " <<  _inputMCsCollection << " does not exist in event "<< evt->getEventNumber() << std::endl ;
           return;
       }	   
       if (!coltrk) {
	      streamlog_out(ERROR) << "   collection  " <<  _colNameTracks << " does not exist in event " <<evt->getEventNumber() << std::endl ;
           return;
       }	   
       if (!rel) {
	      streamlog_out(ERROR) << "   collection  " << _mctrkRelation  << " does not exist in event " <<evt->getEventNumber() << std::endl ;
           return;
       }	   
      
       streamlog_out(DEBUG) << "   collections exist  " <<  std::endl ;

       
       LCCollectionVec* Tracks = new LCCollectionVec( LCIO::TRACK ) ; // OUTPUT collection
       Tracks->setSubset(true);
       LCCollectionVec* highestTrack = new LCCollectionVec( LCIO::TRACK ) ; // OUTPUT collection
       highestTrack->setSubset(true);


       int ntrk = coltrk->getNumberOfElements();
      
       int nmcp = colmcp->getNumberOfElements();
       
       int n,t;
       n=0;t=0;
       /* for(int i = 0; i< nmcp; i++){
	      MCParticle *mcp = dynamic_cast<MCParticle*>(colmcp->getElementAt(i));
	      if(mcp->getGeneratorStatus() == 1){

		     if(mcp->getParents()[0]->getPDG() == 1000024) {
			    t=t+1;
		     }
		     if(mcp->getParents()[0]->getPDG() == -1000024) {
			    n=n+1;
		     }	
	      }

	      }*/
       
       LCObjectVec mc_to_trk;
       if(ntrk < 13 ){

	      for(int j = 0; j < nmcp; j++){
		     MCParticle *mcp = dynamic_cast<MCParticle*>(colmcp->getElementAt(j));
		     if(abs(mcp->getPDG()==11) && mcp->getParents().empty() && mcp->isOverlay()){
			    //the particle is a pair background
		     }
		     else{
	      		    if((rel->getRelatedToObjects(mcp)).size()>0){
		        	    mc_to_trk.push_back(  ( rel->getRelatedToObjects(mcp) )[0]  );
			    }
		     }
	      }
       }
      
       for(int it = 0; it < mc_to_trk.size(); it++ ){
	      for(int it1 = 0; it1 < mc_to_trk.size(); it1++ ){
	      

       }


       sort(mc_to_trk.begin(),mc_to_trk.end());
       reverse(mc_to_trk.begin(),mc_to_trk.end());


       for(int k = 0; k < mc_to_trk.size(); k++ ){
	      Track *trk = dynamic_cast<Track*>(mc_to_trk[k]);
	      
	    
	      if(abs(trk->getTrackState(TrackState::AtIP)->getZ0()) < _z0cut  && abs(trk->getTrackState(TrackState::AtIP)->getD0())< _d0cut){
  
		     Tracks->addElement(trk);

	      }
		     
       }
       evt->addCollection(Tracks, _colNameCutPassedTrks);
       //=========================================================================================
       _nEvt ++ ;	    
}

void CutsForAlgorithm::check(LCEvent * evt){
       // streamlog_out( DEBUG ) << " --- check called ! " << std::endl ; 
       // if( isFirstEvent() ){
       //  AIDAProcessor::histogramFactory( this ) ;
       //   }
}
 
void CutsForAlgorithm::end(){


}
