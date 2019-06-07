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

void isr_energy()
{
       //////////////////////////////////////////////////////////
       //   This file has been automatically generated 
       //     (Thu Feb  4 15:07:08 2016 by ROOT version5.28/00f)
       //   from TTree MyLCTuple/columnwise ntuple with LCIO data
       //   found on file: mysgv_1-0.1.root
       //////////////////////////////////////////////////////////


       //Reset ROOT and connect tree file
       gStyle->SetOptStat(0);
       gROOT->Reset();

         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm770_merged_overlay.root");
	 //  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/desy.de/user/s/swathi/my_nafhh/root_files/c10_010verlay_770.root");
       if (!f) {
	     
	         f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm770_merged_overlay.root");
		 // f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/root_files/c10_010verlay_770.root");
       }

       TTree *MyLCTuple = (TTree*)gDirectory->Get("MyLCTuple");
       cout << "step1" << endl;
       //Declaration of leaves types
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
       MyLCTuple->SetBranchAddress("tstnl",&tstnl);
       MyLCTuple->SetBranchAddress("tsloc",&tsloc);
       MyLCTuple->SetBranchAddress("trsip",&trsip);
       MyLCTuple->SetBranchAddress("tscov",&tscov);
       MyLCTuple->SetBranchAddress("tszze",&tszze);
       MyLCTuple->SetBranchAddress("tsdze",&tsdze);
      
       TH1F *h1 =new TH1F("mcvtz Vs Groups>>h1","",100,0,300);
       TH1F *h2 =new TH1F("mcvtz Vs Groups>>h2","",100,0,300);
       int nevent = MyLCTuple->GetEntries();
       int event=0;
       for (int ievt = 0; ievt < nevent; ievt++) {
	  
	      MyLCTuple->GetEntry(ievt);
	   
	      event=event+1;
 	  
	      for(int is = 0; is < nrec; is++ ){
		    
		     if(rctyp[is] == 22){
			    //  cout<<"The reco pdg num "<< rctyp[is]<<endl;
			    h1->Fill(rcene[is]);
 
			     }

	      }

	      for(int isr = 0; isr < nmcp; isr++ ){
	      	     if(mcpdg[isr] == 22 && (mcgst[isr]==1||mcgst[isr]==0 )){
			    //  cout<<"The energy is "<<mcene[isr]<<endl;
	       		    h2->Fill(mcene[isr]);

	       	     }

	      }
       }

       TCanvas* c2 = new TCanvas ("c","c",800,600);
       c2->Divide(1,2);
       c2->cd(1);
       h2->Draw("hist");
       c2->cd(2);
       h1->Draw("hist");
}


