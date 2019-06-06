#include "InputManager.cpp"
#include <iostream>
#include <stdlib.h>
#include "TFile.h"
#include "TNtupleD.h"
#include "TH1.h"

void Addweight(){


       InputManager input_manager;
       input_manager.setInputDirectory( "/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files" );
       input_manager.setFilenameExtension( "root" );
       input_manager.findFiles();
       
       vector<string> root_file_paths {};
       input_manager.getFilePaths( root_file_paths );


       for (auto & filename: root_file_paths) { 
	     
	      TFile *file = TFile::Open( filename.c_str(), "update" );
	     
	      cout<< filename <<endl;
	      TTree *nt = (TTree*)file->Get("MyLCTuple");
	     
 
	      // double target_lumi = 500.0;
	      Float_t weight_left=0.0;
	      Float_t weight_right=0.0;
	     
	      Float_t evsig, evpoe, evpop;
	      Int_t cutpassparameter;
	      
	      nt->SetBranchAddress( "evpoe", &evpoe );
	      nt->SetBranchAddress( "evpop", &evpop );
	      nt->SetBranchAddress( "evsig", &evsig );
	      nt->SetBranchAddress( "cutpassparameter", &cutpassparameter );
	     

	      
	      TBranch *br = nt->Branch( "weight_left", &weight_left, "weight_left/F" );
	      TBranch *br2 = nt->Branch( "weight_right", &weight_right, "weight_right/F" );
	      int nevent = nt->GetEntries();
	     
	      // cout<<"The cut pass parameter is "<<cutpassparameter<<endl;
	      cout<<"nevent "<<nevent<<endl;
	      for( int i = 0; i < nevent; i++ ){
		    
		     nt->GetEntry(i);

		     if(cutpassparameter==1){
			    // if( i % 50000 == 0 ){ cout << i << " events processed." << endl; }
			  
			   

			    if(evpop ==  1.0 && evpoe == -1.0){
				   weight_left = 0.585* 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.035 * 500.0 * (evsig /(Float_t) nevent) ;

			    }
			    else if (evpop == -1.0 && evpoe ==  1.0){
				   weight_left = 0.035 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.585 * 500.0 * (evsig /(Float_t) nevent) ;
			    }
			    else if (evpop ==  1.0 && evpoe ==  1.0) {
				   weight_left = 0.065 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right= 0.315 * 500.0 * (evsig /(Float_t) nevent) ;

			    }
			    else if (evpop == -1.0 && evpoe == -1.0) {
				   weight_left =  0.315 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.065 * 500.0 * (evsig /(Float_t) nevent) ;

			    }
			    // gammagamma
			    else if (evpop ==  0.0 && evpoe ==  0.0) {
				   weight_left =   1.0 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right =   1.0 * 500.0 * (evsig /(Float_t) nevent) ;
			    }
			    else if (evpop ==  1.0 && evpoe ==  0.0) {
				   weight_left =   0.65 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.35 * 500.0 * (evsig / (Float_t)nevent) ;
			    }
			    else if (evpop == -1.0 && evpoe ==  0.0) {
				   weight_left =   0.35 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.65 * 500.0 * (evsig /(Float_t) nevent) ;
			    }
			    else if (evpop ==  0.0 && evpoe ==  1.0) {
				   weight_left =   0.1 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right = 0.9 * 500.0 * (evsig /(Float_t) nevent) ;
			    }
			    else if (evpop ==  0.0 && evpoe == -1.0) {
				   weight_left =   0.9 * 500.0 * (evsig /(Float_t) nevent) ;
				   weight_right =0.1 * 500.0 * (evsig /(Float_t) nevent) ;
			    }


		     }
		    
		     br->Fill();
		     br2->Fill();
	      }
	      cout<<"Polarization e: "<<evpoe<<" polarization p: "<<evpop<<" weight: "<<weight_left<< " weight2: "<<weight_right<<endl;
	      // file->Write();
	       file->Write("",TObject::kOverwrite);
 
	     
       
       }
     
      
}	      


