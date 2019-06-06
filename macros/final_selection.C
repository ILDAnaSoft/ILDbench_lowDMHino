#include <iostream>
#include<TROOT.h>
#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<TMath.h>
#include<TH2F.h>
#include<TProfile2D.h>
#include<TLorentzVector.h>




void final_selection()

{

       gStyle->SetOptStat(0);
       gROOT->Reset();

        TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/analysis/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eL_pR.root");
      

 if (!f) {
	     
	  f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/analysis/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eL_pR.root");
		


 }
		 TTree *MyLCTuple = (TTree*)gDirectory->Get("MyLCTuple");
		 Int_t           evevt;
		 Int_t           evrun;
		 Float_t         evwgt;
		 Long64_t        evtim;
		 Float_t         evsig;
		 Int_t           evnch;
		 Char_t          evpro[8];
		 Int_t           nmcp;
		 Float_t         mcmox[10000];
		 Float_t         mcmoy[10000];
		 Float_t         mcmoz[10000];
		 Float_t         mcmas[10000];
		 Float_t         mcene[10000];
		 Int_t           mcpdg[10000];
		 Int_t           mcpa0[10000];
		 Int_t           mcpa1[10000];
		 Int_t           mcgst[10000];
		 Int_t           mcsst[10000];
		 Float_t        mccha[10000];
		 Float_t        mcvtx[10000];
		 Float_t        mcvty[10000];
		 Float_t        mcvtz[10000];
		 // Int_t           ngrp;
		 //Int_t           gSigGrp[1000];
		 //Int_t           gBkgGrp[1000];
		 //Int_t           gMixGrp[1000];
		 //Int_t           nHighd0sig;
		 //Int_t           nHighd0bkg;
		 //int             nTrksInGrp[1000];
		 //int            grcid[15][20];
		 //int            gtrkid[15][20];
		 Int_t           nrec;
		 Int_t           pipdg[10000];
		 Int_t           pityp[10000];
		 Float_t         rcmox[10000];
		 Float_t         rcmoy[10000];
		 Float_t         rcmoz[10000];
		 Float_t         rcmas[10000];
		 Float_t         rcene[10000];
		 Int_t           rctyp[10000];
		 Int_t           m2rnrel;
		 Int_t           m2rf[10000];
		 Int_t           m2rt[10000];
		 Float_t            m2rw[10000];
		 Int_t           rcori[10000];
		 Int_t           r2mnrel;
		 Int_t           r2mf[10000];
		 Int_t           r2mt[10000];
		 Float_t           r2mw[10000];
		 Int_t           m2tnrel;
		 Int_t           m2tf[10000];
		 Int_t           m2tt[10000];
		 Float_t           m2tw[10000];
		 Int_t           r2tnrel;
		 Int_t           r2tf[10000];
		 Int_t           r2tt[10000];
		 Float_t           r2tw[10000];
		 Float_t         tsrpx[10000];
		 Float_t         tsrpy[10000];
		 Int_t           ntrk;
		 Int_t           ntrst;
		 Int_t        mcda0[10000];
		 Int_t           mcda1[10000];
		 Int_t           mcda2[10000];
		 Int_t            mcda3[10000];
		 Int_t           mcda4[10000];
		 Float_t         tsome[10000];
		 Float_t         tsphi[10000];
		 Float_t         tstnl[10000];
		 Int_t         tsloc[10000];
		 Int_t         trori[10000];
		 Int_t         trsip[10000];
		 Float_t         tscov[10000][15];
		 Float_t         tszze[10000];
		 Float_t         tsdze[10000];


		 // Set branch addresses.
		 MyLCTuple->SetBranchAddress("evevt",&evevt);
		 MyLCTuple->SetBranchAddress("evrun",&evrun);
		 MyLCTuple->SetBranchAddress("evwgt",&evwgt);
		 MyLCTuple->SetBranchAddress("evtim",&evtim);
		 MyLCTuple->SetBranchAddress("evsig",&evsig);
		 MyLCTuple->SetBranchAddress("evnch",&evnch);
		 MyLCTuple->SetBranchAddress("evpro",evpro);
		 MyLCTuple->SetBranchAddress("nmcp",&nmcp);
		 MyLCTuple->SetBranchAddress("mcmox",mcmox);
		 MyLCTuple->SetBranchAddress("mcmoy",mcmoy);
		 MyLCTuple->SetBranchAddress("mcmoz",mcmoz);
		 MyLCTuple->SetBranchAddress("mcmas",mcmas);
		 MyLCTuple->SetBranchAddress("mcpdg",mcpdg);
		 MyLCTuple->SetBranchAddress("mcgst",mcgst);
		 MyLCTuple->SetBranchAddress("mcsst",mcsst);
		 MyLCTuple->SetBranchAddress("mcene",mcene);
		 MyLCTuple->SetBranchAddress("nrec",&nrec); 
		 MyLCTuple->SetBranchAddress("rcmox",rcmox);
		 MyLCTuple->SetBranchAddress("rcmoy",rcmoy);
		 MyLCTuple->SetBranchAddress("rcmoz",rcmoz);
		 MyLCTuple->SetBranchAddress("rcori",&rcori);
		 MyLCTuple->SetBranchAddress("rcmas",rcmas);
		 MyLCTuple->SetBranchAddress("rcene",rcene);
		 MyLCTuple->SetBranchAddress("rctyp",rctyp);
		 MyLCTuple->SetBranchAddress("m2rnrel",&m2rnrel);
		 MyLCTuple->SetBranchAddress("m2rf",&m2rf);
		 MyLCTuple->SetBranchAddress("m2rt",&m2rt);
		 MyLCTuple->SetBranchAddress("m2rw",&m2rw);
		 MyLCTuple->SetBranchAddress("r2tnrel",&r2tnrel);
		 MyLCTuple->SetBranchAddress("r2tf",&r2tf);
		 MyLCTuple->SetBranchAddress("r2tt",&r2tt);
		 MyLCTuple->SetBranchAddress("r2tw",&r2tw);
		 MyLCTuple->SetBranchAddress("r2mnrel",&r2mnrel);
		 MyLCTuple->SetBranchAddress("r2mf",&r2mf);
		 MyLCTuple->SetBranchAddress("pipdg",&pipdg);
		 MyLCTuple->SetBranchAddress("pityp",&pityp);
		 MyLCTuple->SetBranchAddress("r2mt",&r2mt);
		 MyLCTuple->SetBranchAddress("r2mw",&r2mw);
		 MyLCTuple->SetBranchAddress("m2tnrel",&m2tnrel);
		 MyLCTuple->SetBranchAddress("m2tf",&m2tf);
		 MyLCTuple->SetBranchAddress("m2tt",&m2tt);
		 MyLCTuple->SetBranchAddress("m2tw",&m2tw);
		 MyLCTuple->SetBranchAddress("tsrpx",&tsrpx);
		 MyLCTuple->SetBranchAddress("tsrpy",&tsrpy);
		 MyLCTuple->SetBranchAddress("ntrk",&ntrk);
		 MyLCTuple->SetBranchAddress("ntrst",&ntrst);
		 MyLCTuple->SetBranchAddress("mcpa0",&mcpa0);
		 MyLCTuple->SetBranchAddress("mcpa1",&mcpa1);
		 MyLCTuple->SetBranchAddress("mcda0",&mcda0);
		 MyLCTuple->SetBranchAddress("mcda1",&mcda1);
		 MyLCTuple->SetBranchAddress("mcda2",&mcda2);
		 MyLCTuple->SetBranchAddress("mcda3",&mcda3);
		 MyLCTuple->SetBranchAddress("mcda4",&mcda4);
		 MyLCTuple->SetBranchAddress("mccha",&mccha);
		 MyLCTuple->SetBranchAddress("mcvtx",&mcvtx);
		 MyLCTuple->SetBranchAddress("mcvty",&mcvty);
		 MyLCTuple->SetBranchAddress("mcvtz",&mcvtz);
		 MyLCTuple->SetBranchAddress("tsome",&tsome);
		 MyLCTuple->SetBranchAddress("tsphi",&tsphi);
		 MyLCTuple->SetBranchAddress("trori",&trori);
		 MyLCTuple->SetBranchAddress("tstnl",&tstnl);
		 MyLCTuple->SetBranchAddress("tsloc",&tsloc);
		 MyLCTuple->SetBranchAddress("trsip",&trsip);
		 MyLCTuple->SetBranchAddress("tscov",&tscov);
		 MyLCTuple->SetBranchAddress("tszze",&tszze);
		 MyLCTuple->SetBranchAddress("tsdze",&tsdze);
		 // MyLCTuple->SetBranchAddress("nHighd0sig",&nHighd0sig);
		 // MyLCTuple->SetBranchAddress("nHighd0bkg",&nHighd0bkg);
		 // MyLCTuple->SetBranchAddress("gSigGrp",&gSigGrp);
		 // MyLCTuple->SetBranchAddress("gBkgGrp",&gBkgGrp);
		 // MyLCTuple->SetBranchAddress("gMixGrp",&gMixGrp);
		 // MyLCTuple->SetBranchAddress("ngrp",&ngrp);
		 // MyLCTuple->SetBranchAddress("nTrksInGrp",&nTrksInGrp);
		 // MyLCTuple->SetBranchAddress("grcid",&grcid);
		 // MyLCTuple->SetBranchAddress("gtrkid",&gtrkid);
		 

		 TH1F *h1 =new TH1F("mcvtz Vs Groups>>h1","",100,200,500);
		 int event=0;
		 int nevent =MyLCTuple ->GetEntries();
		 int n = 0;
		 int particle_id;
		 int ne[10];
		 int nm[10];
		 int np[10];
		 int nk[10];
		 int nle=0,nmu=0,npi=0,nka=0;

		 float weight = float(500) *  float(130.046)/float(64989) ;
 cout<<"the weight is "<<weight<< " " << evsig << endl;
		 for (int ievt = 0; ievt < nevent; ievt++) {
		
			MyLCTuple->GetEntry(ievt);
			float overlay_energy=0.0;
			bool b =false;
			bool c =false;
			int index=0;
			int index1=0;
			int index2=0;
			float Eisr=0.0;
			float Mass=0.0;
			float costheta[1000]{};


			for(int irc = 0; irc < nrec; irc++){
			      

			       costheta[irc] = rcmoz[irc]/(sqrt(pow(rcmox[irc],2)+pow(rcmoy[irc],2)+pow(rcmoz[irc],2)));

			      
			       if(rctyp[irc]==22 && rcene[irc]>10 && costheta[irc] < 0.993 ){
				     
				      if(Eisr < rcene[irc]){
					     Eisr = rcene[irc];
					     index = irc;
					    
				      }

			       }		
			}

		



			/*	int rc;

			for(int itrk = 0; itrk < ntrk; itrk++){

			       if(trori[itrk]==2){


				      for(int k=0; k < r2tnrel; k++){
					     if(r2tt[k]==itrk){
						    rc=r2tf[k];
						    if(abs(rctyp[rc])==211){
							   index2=rc;
							   b = true;   

						    }					 
						    else if(abs(rctyp[rc])==11 || abs(rctyp[rc])==13){
							   index2=rc;
							   c=true;
						    }    

					     }
				      }
			       }
			}
			int tracks;

			for(int igrp=0; igrp < ngrp; igrp++){
			       tracks=nTrksInGrp[igrp];
			       for(int itrk =0; itrk < tracks; itrk++){

				      if(b==true){
					     if(nTrksInGrp[igrp]==1 && (abs(rctyp[grcid[igrp][0]])==11 || abs(rctyp[grcid[igrp][0]])==13)){
						    index1=grcid[igrp][0];		  
					     }
					   
					    

				      }  
		
				      else if(c==true){
					     if(nTrksInGrp[igrp]==1 && abs(rctyp[grcid[igrp][0]])==211){
						    index1=grcid[igrp][0];
		  
					     }
					   
					    

				      }


			       }
			
			}

			for(int irec=0; irec < nrec; irec++){
			      
			       if(irec!=index ||irec!=index1 || irec!=index2 ){

				      overlay_energy+=rcene[irec];
			       }
			      

			       }*/

		      
			//	cout<<"the energy of isr "<<rcene[index]<<endl;
			//	cout<<"maths "<<2*(500)*rcene[index]<<endl;
		
				Mass = (sqrt(abs(250000 - (2*(500)*rcene[index])))) ;
			//	cout<<"The mass is "<< Mass<<endl;
			h1->Fill(Mass);
		
		 }
		 h1-> Scale(1. / weight);
		 TCanvas* c2 = new TCanvas ("c","c",800,600);
		 c2->cd();
		 h1->SetFillColor(kGreen+2);
		 h1->Draw("hist");


 }

 

