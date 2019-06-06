#include "InputManager.cpp"
#include <TChain.h>
#include<TROOT.h>
#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<TMath.h>
#include<TH1F.h>
#include "TLegend.h"
 
void grp_num() {

       gStyle->SetOptStat(0);
       gROOT->Reset();
       InputManager input_manager;
       input_manager.setInputDirectory( "/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files" );
       input_manager.setFilenameExtension( "root" );
       input_manager.findFiles();

       vector<string> root_file_paths {};
       input_manager.getFilePaths( root_file_paths );

       // cout<<"The files are:\n";

       float Luminosity=500;

       TChain chain("MyLCTuple");
      

       for (auto & path: root_file_paths) {
	      // cout << path <<endl; 
	      // cout << "\n";
	      //  if(path != "/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eL_pR.root") continue;
	      chain.Add(path.c_str());

       }
 
       Int_t nrec;
       Int_t ntrk;
       Float_t rcene[1000];
       Float_t rcmox[10000];
       Float_t rcmoy[10000];
       Float_t rcmoz[10000];
       Int_t cutpassparameter;
       Float_t evsig;
       Int_t  rctyp[1000];
       char   evpro[100];
       Int_t evnch;
       Float_t weight_left;
       Float_t weight_right;
       Int_t ngrp;
       Float_t tsome[1000];
       Int_t trsip[1000];
       Int_t trori[1000];
       Int_t gtrkid[1000][15];
       Int_t nTrksInGrp[1000];

       float a=0.,b=0.,c=0.,d=0.,e=0.,f=0.,g=0.;
       float a1=0.,b1=0.,c1=0.,d1=0.,e1=0.,f1=0.,g1=0.;
       chain.SetBranchAddress("nrec",&nrec);
       chain.SetBranchAddress("ntrk",&ntrk);
       chain.SetBranchAddress("rcene",&rcene);
       chain.SetBranchAddress("rcmox",&rcmox);
       chain.SetBranchAddress("rcmoy",&rcmoy);
       chain.SetBranchAddress("rcmoz",&rcmoz);
       chain.SetBranchAddress("cutpassparameter",&cutpassparameter);
       chain.SetBranchAddress("evsig",&evsig);
       chain.SetBranchAddress("rctyp",&rctyp);
       chain.SetBranchAddress("evpro",&evpro);
       chain.SetBranchAddress("evnch",&evnch);
       chain.SetBranchAddress("weight_left",&weight_left);
       chain.SetBranchAddress("weight_right",&weight_right);
       chain.SetBranchAddress("nTrksInGrp",&nTrksInGrp);
       chain.SetBranchAddress("trori",&trori);
       chain.SetBranchAddress("gtrkid",&gtrkid);
       chain.SetBranchAddress("ngrp",&ngrp);
       chain.SetBranchAddress("tsome",&tsome);
       chain.SetBranchAddress("trsip",&trsip);



      
       TH1F* h1 = new TH1F("Ngrp1","", 15, -0.5, 14.5);
       TH1F* h2 = new TH1F("Ngrp2","", 15, -0.5, 14.5);
       TH1F* h3 = new TH1F("Ngrp3","", 15, -0.5, 14.5);
       TH1F* h4 = new TH1F("Ngrp4","", 15, -0.5, 14.5);
       TH1F* h5 = new TH1F("Ngrp5","", 15, -0.5, 14.5);
       TH1F* h6 = new TH1F("Ngrp6","", 15, -0.5, 14.5);
       TH1F* h7 = new TH1F("Ngrp7","", 15, -0.5, 14.5);

       TH1F* h21 = new TH1F("Ngrp11","", 15, -0.5, 14.5);
       TH1F* h22 = new TH1F("Ngrp22","", 15, -0.5, 14.5);
       TH1F* h23 = new TH1F("Ngrp33","", 15, -0.5, 14.5);
       TH1F* h24 = new TH1F("Ngrp44","", 15, -0.5, 14.5);
       TH1F* h25 = new TH1F("Ngrp55","", 15, -0.5, 14.5);
       TH1F* h26 = new TH1F("Ngrp66","", 15, -0.5, 14.5);
       TH1F* h27 = new TH1F("Ngrp77","", 15, -0.5, 14.5);



       h7->GetYaxis()->SetTitle("# Events");
       h7->GetXaxis()->SetTitle("E_{soft} [GeV]");
      
       int grp_ind = 0;
       float Eisr = 0, Esoft = 0;
       float costheta[1000];
       int index = 0;
       int isr;
       int ch=0,n=0,f2=0,f4=0,f5=0,f6=0;
       std::vector<std::string> chargino ={"np-hino-vldm_770_cc11g"};
       std::vector<std::string> Neutralino ={"np-hino-vldm_770_nn12g"};
       std::vector<std::string> ee_2f = {"2f_z_h", "2f_z_l", "2f_z_bhabhag"};
       std::vector<std::string> ee_4f = {"4f_ww_h", "4f_ww_l", "4f_zzorww_h" ,"4f_sw_l" ,"4f_sze_l", "4f_szeorsw_l", "4f_sznu_l" ,"4f_zzorww_l" ,"4f_sw_sl" ,"4f_sze_sl" ,"4f_sznu_sl" ,"4f_ww_sl", "4f_zz_sl"};
       std::vector<std::string> egamma_5f = {"ea_evvvv","ea_lvvvv","ea_vvvxy","ea_evvxx","ea_lvvxx","ea_vxxxy","ea_eeevv","ea_eelvv","ea_eevxy","ea_ellvv","ea_lllvv","ea_llvxy","ea_evvyy","ea_lvvyy","ea_vxyyy","ea_elevv","ea_elvxy","ea_evexy","ea_evlxy","ea_exxyy","ea_exxxx","ea_eeexx","ea_ellxx","ea_eeeee","ea_eeell","ea_eeeyy","ea_ellll","ea_ellyy","ea_eyyyy","ae_evvvv","ae_lvvvv","ae_vvvxy","ae_evvxx","ae_lvvxx","ae_vxxxy","ae_eeevv","ae_eevxy","ae_ellvv","ae_lllvv","ae_llvxy","ae_evvyy","ae_lvvyy","ae_vxyyy","ae_elevv","ae_elvxy","ae_evexy","ae_evlxy","ae_exxyy","ae_exxxx","ae_eeexx","ae_ellxx","ae_eeeee","ae_eeell","ae_eeeyy","ae_ellll","ae_ellyy","ae_eyyyy"};

       std::vector<std::string> ee_6f = {"eeveev","eevelv","eevlev","eevllv","eeveyx","eexyev","eevlyx","llvelv","llvlev","llvllv","llveyx","llxyev","llvlyx","llxylv","llxyyx","eexylv","eexyyx","yyveev","yyvelv","yyvlev","yyvllv","yyveyx","yyxyev","yyvlyx","yyxylv","yyuyyu","yyuyyc","yycyyu","vvveev","vvvelv","vvvlev","vvvllv","vvveyx","vvxyev","vvvlyx","vvxyyx","xxveev","xxvelv","xxvlev","xxvllv","xxveyx","xxxyev","xxvlyx","xxxylv","xxxyyx","vvvvxx","vvvvyy","xxxxee","xxxxvv","xxxxll","xxxxxx","eeeeee","eeeell","llllee","llllll","eeeexx","eeeeyy","eellxx","eellyy","yyyyee","yyyyll","yyyyyy","yyyyvv"};
      
       std::vector<std::string> aa_4f = {"aa_eevv","aa_levv","aa_vexy","aa_elvv","aa_llvv","aa_vlxy","aa_evxy","aa_lvxy","aa_xxyy","aa_vvxx","aa_xxxx","aa_vvyy","aa_eexx","aa_llxx","aa_eeee","aa_eell","aa_eeyy","aa_llll","aa_llyy","aa_yyyy"};




       Int_t nevent = chain.GetEntries();
       cout<<"The number of events "<<nevent<<endl;

       for (int evt=0; evt < nevent; evt++) {
	      chain.GetEntry(evt);

	      Esoft = 0;
	      Eisr = 0;
	      bool event_passed=false;
	      int charge1 = 0;
	      if(cutpassparameter==1){


		     // float weight = Luminosity *  evsig/nevent ;
		     // float weight=1.1;
		     // cout<<"the event is "<<evpro<<endl;
		     // cout<<"Luminosity: "<<Luminosity<<endl;
		     // cout<<"cross section: "<<evsig<<endl;
		     // cout<<"The number of events: "<<nevent<<endl; 
		     //  cout<<"The weight is "<<weight<<endl;
		    


		     for(int irc = 0; irc < nrec; irc++){
			    costheta[irc] = rcmoz[irc]/(sqrt(pow(rcmox[irc],2)+pow(rcmoy[irc],2)+pow(rcmoz[irc],2))); 
			    if(rctyp[irc]==22 && rcene[irc]>10 && costheta[irc] < 0.993 ){
				 
			    
				   if(Eisr < rcene[irc]){
					  Eisr = rcene[irc];
					  index = irc;
				   }

			    }
		     }
	       
		     for(int itrk = 0; itrk < ntrk; itrk++){
			    if(trori[itrk]==2){
				   int its =  trsip[itrk] ;
				   charge1 = tsome[its]/abs(tsome[its]);
				   //  cout<<"The tsome is "<<tsome[its]<<endl;			       
			    }


		     }

		     //  cout<<"The charge is "<<charge1<<endl;
		     if(charge1 > 0){
				   
			    for(int grp =0; grp < ngrp; grp++){
				   if(nTrksInGrp[grp]==1){
					  int igts= trsip[gtrkid[grp][0]] ;
					  if(tsome[igts] < 0){
						 grp_ind=grp;
						 event_passed=true;   

					  }
				   }
							
			    }
					  

		     }

		     else if(charge1 < 0){
			    for(int grp =0; grp < ngrp; grp++){

				   if(nTrksInGrp[grp]==1){
					  int igtss= trsip[gtrkid[grp][0]] ;
					  if(tsome[igtss] > 0){
						 grp_ind=grp;
						 event_passed=true;   

					  }
				   }							
			    }			
		     }


		     if(event_passed == true){
			    for(int igr = 0; igr < ngrp; igr++ ){
				   if(igr !=  grp_ind){

			   
					  //	cout<<"The soft energy is "<< Esoft<<endl;

	

					  // cout<<"the event is "<<evpro<<endl;

					  for(int ch=0; ch < chargino.size();ch++){

						 if(evpro==chargino[ch]){
							// cout<<"The soft energy is "<< Esoft<<endl;
					 
							h1->Fill(nTrksInGrp[igr],weight_left);
						
							h21->Fill(nTrksInGrp[igr],weight_right);				   
						 }


					  }

					  for(int n=0; n < Neutralino.size();n++){
						 if(evpro == Neutralino[n]){
					 
							h2->Fill(nTrksInGrp[igr],weight_left);
						
							h22->Fill(nTrksInGrp[igr],weight_right);
					  
						
						 }
					  }
				   

					  for(int f2=0; f2 < ee_2f.size();f2++){
						 if(evpro == ee_2f[f2]){
					  
							h3->Fill(nTrksInGrp[igr],weight_left);
					       
							h23->Fill(nTrksInGrp[igr],weight_right);
						 }

					  }
			   

				   
			     

					  for(int f4=0; f4 < ee_4f.size();f4++) {
					  
						 if(evpro == ee_4f[f4]){
							h4->Fill(nTrksInGrp[igr],weight_left);
							h24->Fill(nTrksInGrp[igr],weight_right);	 					 
						
						 }
					  }
			    
				    
			    

					  for(int f5=0; f5 < egamma_5f.size();f5++) {
						 if(evpro == egamma_5f[f5]){
				   					  
							h5->Fill(nTrksInGrp[igr],weight_left);
							h25->Fill(nTrksInGrp[igr],weight_right);
				   
					  
						
						 }

					  }

			   

					  for(int f6=0; f6 < ee_6f.size();f6++) {

						 if(evpro == ee_6f[f6]){
							h6->Fill(nTrksInGrp[igr],weight_left);
							h26->Fill(nTrksInGrp[igr],weight_right);	
				    
						 }
					  }

					  for(int f7=0; f7 < aa_4f.size();f7++) {

						 if(evpro == aa_4f[f7]){
							h7->Fill(nTrksInGrp[igr],weight_left);
							h27->Fill(nTrksInGrp[igr],weight_right);	
				    
						 }
					  }
			    
			   
		

				   }
			    }
		     }
	      }
       }

       h1->SetLineColor(40);
       h2->SetLineColor(42);
       h3->SetLineColor(45);
       h4->SetLineColor(46);
       h5->SetLineColor(31);
       h6->SetLineColor(35);
       h7->SetLineColor(28);
       
       h21->SetLineColor(40);
       h22->SetLineColor(42);
       h23->SetLineColor(45);
       h24->SetLineColor(46);
       h25->SetLineColor(31);
       h26->SetLineColor(35);
       h27->SetLineColor(28);

       h1->SetLineWidth(3);
       h2->SetLineWidth(3);
       h3->SetLineWidth(3);
       h4->SetLineWidth(3);
       h5->SetLineWidth(3);
       h6->SetLineWidth(3);
       h7->SetLineWidth(3);
       
       h21->SetLineWidth(3);
       h22->SetLineWidth(3);
       h23->SetLineWidth(3);
       h24->SetLineWidth(3);
       h25->SetLineWidth(3);
       h26->SetLineWidth(3);
       h27->SetLineWidth(3);

       

       //Fix the colours

       auto leg = new TLegend(0.72,0.61,0.92,0.91);

       leg->AddEntry(h1," #tilde{#chi}^{+}_{1} #tilde{#chi}^{-}_{1}","l");
       leg->AddEntry(h2,"#tilde{#chi}^{0}_{1} #tilde{#chi}^{0}_{2}","l");
       leg->AddEntry(h3,"ee#rightarrow 2f","l");
       leg->AddEntry(h4,"ee#rightarrow 4f","l");
       leg->AddEntry(h5,"e#gamma#rightarrow 5f","l");
       leg->AddEntry(h6,"ee#rightarrow 6f","l");
       leg->AddEntry(h7,"#gamma#gamma#rightarrow 4f","l");


       auto leg2 = new TLegend(0.72,0.61,0.92,0.91);

       leg2->AddEntry(h21," #tilde{#chi}^{+}_{1} #tilde{#chi}^{-}_{1}","l");
       leg2->AddEntry(h22,"#tilde{#chi}^{0}_{1} #tilde{#chi}^{0}_{2}","l");
       leg2->AddEntry(h23,"ee#rightarrow 2f","l");
       leg2->AddEntry(h24,"ee#rightarrow 4f","l");
       leg2->AddEntry(h25,"e#gamma#rightarrow 5f","l");
       leg2->AddEntry(h26,"ee#rightarrow 6f","l");
       leg2->AddEntry(h27,"#gamma#gamma#rightarrow 4f","l");

      


       THStack *hs1 = new THStack();
       hs1->Add(h1);
       hs1->Add(h2);
       hs1->Add(h3);
       hs1->Add(h4);
       hs1->Add(h5);
       hs1->Add(h6);
       hs1->Add(h7);

       THStack *hs2 = new THStack();

       hs2->Add(h21);
       hs2->Add(h22);
       hs2->Add(h23);
       hs2->Add(h24);
       hs2->Add(h25);
       hs2->Add(h26);
       hs2->Add(h27);

      
      
        TCanvas*cweight  = new TCanvas ("weight","weightl",800,600);
	hs1->Draw("hist,nostack");
       leg->Draw();
       hs1->GetXaxis()->SetTitle("N_{trk}");
       hs1->GetYaxis()->SetTitle("# Entries");
       cweight->Modified();
       cweight->SetLogy();
       cweight->SaveAs("/afs/desy.de/user/s/swathi/mypool/ilc-soft-test/method_newsamples/analysis/grpnum_l.pdf","pdf");
       TCanvas* cweight2 = new TCanvas ("weight2","weightr",800,600);
       hs2->Draw("hist,nostack");
       leg2->Draw();
       hs2->GetXaxis()->SetTitle("N_{trk}");
       hs2->GetYaxis()->SetTitle("# Entries");
       cweight2->Modified();
       cweight2->SetLogy();
       cweight2->SaveAs("/afs/desy.de/user/s/swathi/mypool/ilc-soft-test/method_newsamples/analysis/grpnum_r.pdf","pdf");
      
	
      
}
