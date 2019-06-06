#include <iostream>
#include<TROOT.h>
#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<TMath.h>
#include<TH1F.h>
#include "TGraph.h"

using namespace std;
//void draw_ptra(const char* gamma.root)

void pdg()
{
//////////////////////////////////////////////////////////
//   This file has been automatically generated 
//     (Thu Feb  4 15:07:08 2016 by ROOT version5.28/00f)
//   from TTree MyLCTuple/columnwise ntuple with LCIO data
//   found on file: mysgv_1-0.1.root
//////////////////////////////////////////////////////////


//Reset ROOT and connect tree file
  gStyle->SetOptStat(0);
  // gROOT->SetStyle("ildStyle");

   gROOT->Reset();
   // TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Nsgv_BB.root");
 TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm1600_merged_overlay.root");
   if (!f) {
     // f = new TFile("Nsgv_BB.root");
      f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm1600_merged_overlay.root");
   }
   TTree *MyLCTuple = (TTree*)gDirectory->Get("MyLCTuple");

//Declaration of leaves types
 
   Int_t           nrec;

   Int_t           rctyp[10000];
  
   Int_t           mcgst[10000];
   // Set branch addresses.
   MyLCTuple->SetBranchAddress("nrec",&nrec);
 
   MyLCTuple->SetBranchAddress("rctyp",rctyp);
   MyLCTuple->SetBranchAddress("mcgst",mcgst);
  
  
   //     This is the loop skeleton
   //       To read only selected branches, Insert statements like:
   // MyLCTuple->SetBranchStatus("*",0);  // disable all branches
   // TTreePlayer->SetBranchStatus("branchname",1);  // activate branchname
   // int d = 180/45;
   TCanvas *c1=new TCanvas("c1"," ",1000,800);
   TH1F *h2 =new TH1F("PDG of reconstructed particles>>h2","histoname",7,0,7);
   int n=0;
   Long64_t nbytes = 0;
   int  nevent = MyLCTuple->GetEntries();
   Double_t norm= MyLCTuple->GetEntries();
   int nx=0,ny=0,nz=0;
   // h2->GetXaxis()->SetTitle("PID");
  h2->GetYaxis()->SetTitle("Entries");

  const char *binlabels[6]={"#pi^{#pm}","K","e^{#pm}","#mu","#tau","#gamma"};
   for(int i=1;i<7;i++) {
h2->GetXaxis()->SetBinLabel(i,binlabels[i-1]);

   }


   for ( int ievt = 1; ievt < nevent; ievt++)  {
	  nbytes += MyLCTuple->GetEntry(ievt);

	  for(int j=0;j< nrec;j++) {
		 // cout<<"the pipdg is "<<pipdg[j]<<endl;
      
     
		 //  h2->Fill(mcpdg[j]);
	    
		 if(abs(rctyp[j])==211) {
	 
			h2->AddBinContent(1);
		 }
	
		 else if(abs(rctyp[j])==310) {
			h2->AddBinContent(2);

		 }
		 else if(abs(rctyp[j])==11) {
			h2->AddBinContent(3);
		 }


		 else if(abs(rctyp[j])==13) {
			h2->AddBinContent(4);
		
		 }
		
		 else if(abs(rctyp[j])==15) {
			h2->AddBinContent(5);
		 }


		 else if(abs(rctyp[j])==22) {
			h2->AddBinContent(6);
		 }

	  }
      
   }	  
  

   h2->Draw("");
   // h3->Draw("SAME");
   //  h4->Draw("SAME");
}
