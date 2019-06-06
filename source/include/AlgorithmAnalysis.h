#ifndef AlgorithmAnalysis_h
#define AlgorithmAnalysis_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>
#include <vector>
#include <gsl/gsl_rng.h>
#include <EVENT/ReconstructedParticle.h>

using namespace lcio ;
using namespace marlin ;

class TFile;
class TH1F ;
class TTree ;


/** Group Tracks into clusters with consistent z-positions of their vertex, based on the Z0 significance.
 *  Algorithm developed by S.Sasikumar, DESY.
 *  
 *
 * @author F.Gaede, DESY, September 2018
 */

class AlgorithmAnalysis : public Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new AlgorithmAnalysis ; }
  
  AlgorithmAnalysis(const AlgorithmAnalysis&) = delete;
  AlgorithmAnalysis& operator=(const AlgorithmAnalysis&) = delete;

  AlgorithmAnalysis() ;
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;
  
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ; 
  
  
  virtual void check( LCEvent * evt ) ; 
  
  
  /** Called after data processing for clean up.

   */

 

  virtual void end() ;

  
  EVENT::ReconstructedParticle* findPfo(const EVENT::Track *const groupTrack, const EVENT::LCCollection *const pfoCollection);

  bool EventPassedCuts( LCEvent * evt );
  
  
 protected:

  void Clear() ;


  /** Input collection name with Tracks
   */
  std::string _colNameTracks{};
  std::string _colNamePFOs{};
  std::string _colNameTrkGroupPFOs{};
  std::string _colNameTrkGroupVertices{};
  std::string         m_rootFile{};

  float _z0SignificanceCut{};
  
  int _nRun{};
  int _nEvt{};

  int n_without_cuts{};
  int n_track_cut{};
  int n_ISR_cut{};
  int n_missingE_cut{}; 




  TFile              *f{nullptr};
  TH1F *_hcut {nullptr} ;
  TTree              *tree{nullptr};
  // std::vector<TH1F*> _h{};

} ;

#endif



