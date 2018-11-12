#ifndef CutsForAlgorithm_h
#define CutsForAlgorithm_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>
#include <vector>
#include <gsl/gsl_rng.h>

using namespace lcio ;
using namespace marlin ;


class TH1F ;
/** Cuts for tracks used as the input for TrakZVertexGrouping algorithm.
 *  
 *  
 *
 * @author S.Sasikumar, DESY, October 2018
 */
 
class CutsForAlgorithm : public Processor {
  
 public:
  
       virtual Processor*  newProcessor() { return new CutsForAlgorithm ; }
       
       CutsForAlgorithm() ;

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
  
   protected:

  /** Input collection name with Tracks
   */
  std::string _colNameTracks{};
  std::string _inputMCsCollection{};
  std::string _mctrkRelation{};
  std::string  _colNameCutPassedTrks{};
  
 
  float _z0cut {};
  float _d0cut {};
  
  int _nRun{};
  int _nEvt{};

  std::vector<TH1F*> _h{};

} ;

#endif


