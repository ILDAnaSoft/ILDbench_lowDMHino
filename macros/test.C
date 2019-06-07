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
 
void test() {
       gStyle->SetOptStat(0);
       gROOT->Reset();

       TFile *file = TFile::Open("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eL_pR.root","update");

      
       TTree *MyLCTuple = (TTree*)file->Get("MyLCTuple");
      
       Int_t nrec;
       Int_t ntrk;
       Float_t rcene[1000];
       Float_t rcmox[10000];
       Float_t rcmoy[10000];
       Float_t rcmoz[10000];
       Int_t cutpassparameter;
      
       Int_t  rctyp[1000];
       char   evpro[100];
       Int_t evnch;
      
       Int_t ngrp;
       Int_t nTrksInGrp[1000];
       Int_t rccha[1000];
       Int_t trori[1000];
       Int_t gtrkid[1000][15];
       Float_t tsome[1000];
       Int_t NewCut;
       Float_t evsig, evpoe, evpop;
       Float_t weight_left;
       Int_t         trsip[1000];

       MyLCTuple->SetBranchAddress( "evpoe", &evpoe );
       MyLCTuple->SetBranchAddress( "evpop", &evpop );
       MyLCTuple->SetBranchAddress( "evsig", &evsig );
       MyLCTuple->SetBranchAddress("nrec",&nrec);
       MyLCTuple->SetBranchAddress("ntrk",&ntrk);
       MyLCTuple->SetBranchAddress("rcene",&rcene);
       MyLCTuple->SetBranchAddress("rcmox",&rcmox);
       MyLCTuple->SetBranchAddress("rcmoy",&rcmoy);
       MyLCTuple->SetBranchAddress("rcmoz",&rcmoz);
       MyLCTuple->SetBranchAddress("cutpassparameter",&cutpassparameter);
       MyLCTuple->SetBranchAddress("evsig",&evsig);
       MyLCTuple->SetBranchAddress("rctyp",&rctyp);
       MyLCTuple->SetBranchAddress("evpro",&evpro);
       MyLCTuple->SetBranchAddress("evnch",&evnch);
       MyLCTuple->SetBranchAddress("trsip",&trsip);
       MyLCTuple->SetBranchAddress("ngrp",&ngrp);
       MyLCTuple->SetBranchAddress("nTrksInGrp",&nTrksInGrp);
       MyLCTuple->SetBranchAddress("rccha",& rccha);
       MyLCTuple->SetBranchAddress("trori",&trori);
       MyLCTuple->SetBranchAddress("gtrkid",&gtrkid);
       MyLCTuple->SetBranchAddress("tsome",&tsome);
      
       MyLCTuple->SetBranchAddress( "weight_left", &weight_left );
      

      

       TH1F* h1 = new TH1F("charge1","", 2  , 0 , 2  );
       TH1F* h2 = new TH1F("charge2","", 2  , 0, 2  );
       TH1F* h3 = new TH1F("charge3","", 2  , 0, 2  );
       TH1F* h4 = new TH1F("charge4","", 2  , 0, 2  );
       TH1F* h5 = new TH1F("charge5","", 2  , 0, 2  );
       TH1F* h6 = new TH1F("charge6","", 2  , 0, 2  );
       TH1F* h7 = new TH1F("charge7","", 2  , 0, 2  );




       float a=0.,b=0.,c=0.,d=0.,e=0.,f=0.,g=0.;
       float a1=0.,b1=0.,c1=0.,d1=0.,e1=0.,f1=0.,g1=0.;

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
      
       std::vector<std::string> aa_4f = {"aa_eevv" "aa_levv" "aa_vexy" "aa_elvv" "aa_llvv" "aa_vlxy" "aa_evxy" "aa_lvxy" "aa_xxyy" "aa_vvxx" "aa_xxxx" "aa_vvyy" "aa_eexx" "aa_llxx" "aa_eeee" "aa_eell" "aa_eeyy" "aa_llll" "aa_llyy" "aa_yyyy"};
       int event=0;
       int nevent = MyLCTuple->GetEntries();
       cout<<"nevent "<<nevent<<endl;
	      for( int ievt = 0; ievt < 10; ievt++ ){
		    
		     MyLCTuple->GetEntry(ievt);
		     event=event+1;
		     int charge1 = 0;
		     bool event_passed=false;
		     if(cutpassparameter==1){
			    // if( i % 50000 == 0 ){ cout << i << " events processed." << endl; }
			  
		  for(int ch=0; ch < chargino.size();ch++){

				   if(evpro==chargino[ch]){
					  // cout<<"The soft energy is "<< Esoft<<endl;
					 
					  h1->AddBinContent(1,weight_left);
					  a=a+weight_left;	
				   					   
				   }


			    }

			    for(int n=0; n < Neutralino.size();n++){
				   if(evpro == Neutralino[n]){
					 
						
					  h2->AddBinContent(1,weight_left);	
					  b=b+weight_left;
					  
						
				   }
			    }
				   

			    for(int f2=0; f2 < ee_2f.size();f2++){
				   if(evpro == ee_2f[f2]){
					  
					  h3->AddBinContent(1,weight_left);
					  c=c+weight_left;
	
				   
				   }

			    }
			   

				   
			     

			    for(int f4=0; f4 < ee_4f.size();f4++) {
					  
				   if(evpro == ee_4f[f4]){
						
					  h4->AddBinContent(1,weight_left);	 					 
					  d=d+weight_left;	
				   }
			    }
			    
				    
			    

			    for(int f5=0; f5 < egamma_5f.size();f5++) {
				   if(evpro == egamma_5f[f5]){
				   					  
					       
					  h5->AddBinContent(1,weight_left);
					  e=e+weight_left;
					  
						
				   }

			    }

			   

			    for(int f6=0; f6 < ee_6f.size();f6++) {

				   if(evpro == ee_6f[f6]){
					       
					  h6->AddBinContent(1,weight_left);	
					  f=f+weight_left;
				   }
			    }

			    for(int f7=0; f7 < aa_4f.size();f7++) {

				   if(evpro == aa_4f[f7]){
					  h7->AddBinContent(1,weight_left); 
					  g=g+weight_left;	
				    
				   }
			    }
			    

  



			    for(int itrk = 0; itrk < ntrk; itrk++){
				   if(trori[itrk]==2){
					  int its =  trsip[itrk] ;
					  cout<<"Event "<<event<<endl;
					  charge1 = tsome[its]/abs(tsome[its]);
					  cout<<"The tsome is "<<tsome[its]<<endl;			       
				   }


			    }

			    cout<<"The charge is "<<charge1<<endl;
			    if(charge1 > 0){
				   
				   for(int grp =0; grp < ngrp; grp++){
					  if(nTrksInGrp[grp]==1){
						 int igts= trsip[gtrkid[grp][0]] ;
						 if(tsome[igts] < 0){
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
							event_passed=true;   

						 }
					  }

						 
							
				   }			
			    }

				   
			    if(event_passed==true){

				 
				   for(int ch=0; ch < chargino.size();ch++){

					  if(evpro==chargino[ch]){
						 // cout<<"The soft energy is "<< Esoft<<endl;
					 
						 h1->AddBinContent(2,weight_left);
						 a1=a1+weight_left;
				   					   
					  }


				   }

				   for(int n=0; n < Neutralino.size();n++){
					  if(evpro == Neutralino[n]){
					 
						
						 h2->AddBinContent(2,weight_left);	
						 b1=b1+weight_left;
					  
						
					  }
				   }
				   

				   for(int f2=0; f2 < ee_2f.size();f2++){
					  if(evpro == ee_2f[f2]){
					  
						 h3->AddBinContent(2,weight_left);
						 c1=c1+weight_left;
				   
					  }

				   }
			   

				   
			     

				   for(int f4=0; f4 < ee_4f.size();f4++) {
					  
					  if(evpro == ee_4f[f4]){
						
						 h4->AddBinContent(2,weight_left);	 					 
						 d1=d1+weight_left;
					  }
				   }
			    
				    
			    

				   for(int f5=0; f5 < egamma_5f.size();f5++) {
					  if(evpro == egamma_5f[f5]){
				   					  
					       
					 	 h5->AddBinContent(2,weight_left);
				   
						 e1=e1+weight_left;
						
					  }

				   }

			   

				   for(int f6=0; f6 < ee_6f.size();f6++) {

					  if(evpro == ee_6f[f6]){
					       
						 h6->AddBinContent(2,weight_left);	
						 f1=f1+weight_left;
					  }
				   }

				   for(int f7=0; f7 < aa_4f.size();f7++) {

					  if(evpro == aa_4f[f7]){
						 h7->AddBinContent(2,weight_left); 
						 g1=g1+weight_left;
				    
					  }
				   }
			    

  

			    }
			  
 
			   
		     }
	      }



        cout<<"charginos: "<<a<<" neutralino: "<<b<<" 2f :"<<c<<" 4f :"<<d<<" 5f: "<<e<<" 6f: "<<f<<" aa4f: "<<g<<endl;
      
       h1->SetFillColor(40);
       h2->SetFillColor(42);
       h3->SetFillColor(45);
       h4->SetFillColor(46);
       h5->SetFillColor(31);
       h6->SetFillColor(35);
       h7->SetFillColor(28);

       // h21->SetFillColor(40);
       // h22->SetFillColor(42);
       // h23->SetFillColor(45);
       // h24->SetFillColor(46);
       // h25->SetFillColor(31);
       // h26->SetFillColor(35);
       // h27->SetFillColor(28);



       //Fix the colours

       auto leg = new TLegend(0.7,0.65,0.9,0.95);

       leg->AddEntry(h1," #tilde{#chi}^{+}_{1} #tilde{#chi}^{-}_{1}","f");
       leg->AddEntry(h2,"#tilde{#chi}^{0}_{1} #tilde{#chi}^{0}_{2}","f");
       leg->AddEntry(h3,"ee#rightarrow 2f","f");
       leg->AddEntry(h4,"ee#rightarrow 4f","f");
       leg->AddEntry(h5,"e#gamma#rightarrow 5f","f");
       leg->AddEntry(h6,"ee#rightarrow 6f","f");
       leg->AddEntry(h7,"#gamma#gamma#rightarrow 4f","f");

       // auto leg2 = new TLegend(0.7,0.65,0.9,0.95);

       // leg2->AddEntry(h21," #tilde{#chi}^{+}_{1} #tilde{#chi}^{-}_{1}","f");
       // leg2->AddEntry(h22,"#tilde{#chi}^{0}_{1} #tilde{#chi}^{0}_{2}","f");
       // leg2->AddEntry(h23,"ee#rightarrow 2f","f");
       // leg2->AddEntry(h24,"ee#rightarrow 4f","f");
       // leg2->AddEntry(h25,"e#gamma#rightarrow 5f","f");
       // leg2->AddEntry(h26,"ee#rightarrow 6f","f");
       // leg2->AddEntry(h27,"#gamma#gamma#rightarrow 4f","f");



     


       THStack *hs1 = new THStack();
       hs1->Add(h1);
       hs1->Add(h2);
       hs1->Add(h3);
       hs1->Add(h4);
       hs1->Add(h5);
       hs1->Add(h6);
       hs1->Add(h7);

       // THStack *hs2 = new THStack();

       // hs2->Add(h21);
       // hs2->Add(h22);
       // hs2->Add(h23);
       // hs2->Add(h24);
       // hs2->Add(h25);
       // hs2->Add(h26);
       // hs2->Add(h27);


      
      
       TCanvas* c2 = new TCanvas ("weight","c",800,600);
       hs1->Draw("hist");
       leg->Draw();
       // TCanvas* cweight2 = new TCanvas ("weight2","b",800,600);
       // hs2->Draw("hist");
       // leg2->Draw();



}
 
