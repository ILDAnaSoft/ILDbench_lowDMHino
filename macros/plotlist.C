#include <map>
#include <iostream>
#include <map>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TString.h"
#include <string>
#include <sstream>
#include <fstream>
#include <TChain.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TEventList.h>
#include <TCut.h>
#include <TLegend.h>
#include <TCanvas.h>
#include "TH1F.h"
#include "TH2F.h"
#include <THStack.h>
#include <TLine.h>
#include "TF1.h"
#include <TMath.h>
#include <TLorentzVector.h>
//#include <TObject.h>


using namespace std;

void plotlist() {
    gROOT->SetStyle("Plain");
    gStyle->SetOptTitle(0);
    gStyle->SetHistLineWidth(2);
    gStyle->SetLineWidth(2);
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetPadBorderMode(0);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasColor(0);
    gStyle->SetTitleColor(1);
    gStyle->SetStatColor(0);
    // gStyle->SetOptStat(1111110);
   //   //gStyle->SetOptFit(10);
    
    const int nfiles = 13;
    const int nprocmax = 10000; 
    int nfilesused = 13;
    TString names[nfiles];
    TString filenames[nfiles];
    names[0]  = "cc11g_std";
    names[1]  = "nn12g_std";
    names[2]  = "2f_6";
    names[3]  = "1f_3f_6";
    names[4]  = "4f_6";
    names[5]  = "5f_6";
    names[6]  = "6f_background_6";
    names[7]  = "6f_signal_6";
    names[8]  = "aa_2f_6.eW.pW";
    names[9]  = "aa_2f_6.eB.pW";
    names[10]  = "aa_2f_6.eW.pB";
    names[11]  = "aa_2f_6.eB.pB";
    names[12]  = "aa_4f_6all";
    /*
    names[13]  = "cc11g_chi1_167_86";
    names[14]  = "nn12g_chi1_167_86";
    names[15]  = "cc11g_chi1_168_36";
    names[16]  = "nn12g_chi1_168_36";
    names[17]  = "cc11g_chi1_168_86";
    names[18]  = "nn12g_chi1_168_86";
    names[19]  = "cc11g_chi1_169_36";
    names[20]  = "nn12g_chi1_169_36";
    names[21]  = "cc11g_chi1_169_86";
    names[22]  = "nn12g_chi1_169_86";
    names[23]  = "cc11g_chi1_166_36";
    names[24]  = "nn12g_chi1_166_36";
    names[25]  = "cc11g_chi1_166_86";
    names[26]  = "nn12g_chi1_166_86";
    names[27]  = "cc11g_chi1_165_36";
    names[28]  = "nn12g_chi1_165_36";
    names[29]  = "cc11g_chi1_165_86";
    names[30]  = "nn12g_chi1_165_86";
    names[31]  = "cc11g_chi1_164_86";
    names[32]  = "nn12g_chi1_164_86";
    */

    TFile *files[nfiles];
    TTree *trees[nfiles];
    
    const int nclass = 9;
    const int nclassused = 9;
    TChain *chains[nclass];
    TString classnames[nclass];
    TEventList *lists[nclass];
    classnames[0]  = "ch1ch1";
    classnames[1]  = "ne1ne2";
    classnames[2]  = "sm2f";
    classnames[3]  = "sm3f";
    classnames[4]  = "sm4f";
    classnames[5]  = "sm5f";
    classnames[6]  = "sm6f";
    classnames[7]  = "smaa_2f";
    classnames[8]  = "smaa_4f";
    /*
    classnames[9]  = "cc11g_chi1_167_86";
    classnames[10]  = "nn12g_chi1_167_86";
    classnames[11]  = "cc11g_chi1_168_36";
    classnames[12]  = "nn12g_chi1_168_36";
    classnames[13]  = "cc11g_chi1_168_86";
    classnames[14]  = "nn12g_chi1_168_86";
    classnames[15]  = "cc11g_chi1_169_36";
    classnames[16]  = "nn12g_chi1_169_36";
    classnames[17]  = "cc11g_chi1_169_86";
    classnames[18]  = "nn12g_chi1_169_86";
    classnames[19]  = "cc11g_chi1_166_36";
    classnames[20]  = "nn12g_chi1_166_36";
    classnames[21]  = "cc11g_chi1_166_86";
    classnames[22]  = "nn12g_chi1_166_86";
    classnames[23]  = "cc11g_chi1_165_36";
    classnames[24]  = "nn12g_chi1_165_36";
    classnames[25]  = "cc11g_chi1_165_86";
    classnames[26]  = "nn12g_chi1_165_86";
    classnames[27]  = "cc11g_chi1_164_86";
    classnames[28]  = "nn12g_chi1_164_86";
    */

    
    const int ncut =8;	
  
    // select cut level for list
    TString cutnames[ncut+1];
    cutnames[0] = "nocut";
    cutnames[1] = "Ebeamcal";
    cutnames[2] = "nrecopart";
    cutnames[3] = "ISRgamma";
    //  cutnames[3] = "costheta_isr"; 
    cutnames[4] = "costheta";
    cutnames[5] = "Emiss";
    cutnames[6] = "Selection_1pisemihad";
    cutnames[7] = "EboostC";
    cutnames[8] = "ne1ne2_photon";
        
    // variable to plot 
    TString var = "";
    TString xaxistitle0 =  "E_{#gamma}^{max}  [GeV]";  
    TString xaxistitle =  "M_{recoil}  [GeV]"; // Boosted Energy for pion  Energy of Highest Energetic Photons Recoil Mass of Highest Energetic Photon E*_{#pi}
    //int nbins  = 30;
    //float xmin =0;
    //float xmax =1.5;
    //float ymin =  0;
    //float ymax = 20;
    
    
    // y34
    TH1F *h_EboostC[nclass][ncut+1];
    TH1F *h_EboostC_log[nclass][ncut+1];
    TH1F *h_EboostN_log[nclass][ncut+1];
    TH1F *h_EboostN[nclass][ncut+1];
    TH1F *h_EboostC_Mreccut[nclass][ncut+1];
    TH1F *h_EboostN_Mreccut[nclass][ncut+1];
    TH1F *h_Mrecoil[nclass][ncut+1];
    TH2F *h_2dC[nclass][ncut+1];
    TH2F *h_2dN[nclass][ncut+1];
    TH1F *h_Egmax[nclass][ncut+1];
    TH1F *h_Nrecop[nclass][ncut+1];
    TH1F *h_Nrecop1[nclass][ncut+1];
    TH1F *h_Emiss[nclass][ncut+1];
    TH1F *h_Emiss2[nclass][ncut+1];
    TH1F *h_Ptmiss[nclass][ncut+1];
    //TH1F *h_Pxmiss[nclass][ncut+1];
    // TH1F *h_Pymiss[nclass][ncut+1];
    TH1F *h_Pzmiss[nclass][ncut+1];
    TH2F *h_2dmiss[nclass][ncut+1];
    TH2F *h_2dmiss2[nclass][ncut+1];
    TH2F *h_2dmissP[nclass][ncut+1];
    TH1F *h_Phimiss[nclass][ncut+1];
    TH1F *h_Phiother[nclass][ncut+1];
    TH1F *h_Thetaother[nclass][ncut+1];
    TH1F *h_Etaother[nclass][ncut+1];
    
    TH1F *h_Evis_Pandora[nclass][ncut+1];
    TH1F *h_Evis_PandBeam[nclass][ncut+1];
    TH1F *h_Evis_vPandBeam[nclass][ncut+1];
    TH1F *h_Ptvis[nclass][ncut+1];
    TH1F *h_Cosgmax[nclass][ncut+1];
    TH1F *h_Cosother[nclass][ncut+1];
    TH1F *h_Ptother[nclass][ncut+1];
    TH1F *h_Ptother2[nclass][ncut+1];

    TH1F *h_NBeamCalPTrue[nclass][ncut+1];
    TH1F *h_NBeamCalPSeen[nclass][ncut+1];
    TH1F *h_EBeamCalPartTrue[nclass][ncut+1];
    TH1F *h_EBeamCalPartSeen[nclass][ncut+1];
    TH1F *h_EBeamCalPartSum[nclass][ncut+1];
    TH2F *h_2dBeamCal[nclass][ncut+1];

    TH2F *h_2dPmiss[nclass][ncut+1];

    TH1F *h_MeanMchi[nclass][ncut+1];

    double  Nsig_chi[nclass], Nnosig_chi[nclass], Nsig_chi_sel[nclass], Nnosig_chi_sel[nclass], Nsig_chi0[nclass], Nnosig_chi0[nclass], Nsig_chi0_sel[nclass], Nnosig_chi0_sel[nclass];
    
    char proc[100];
    // float fvar;
    
    // create chains, book histos
    for (int i = 0; i < nclassused; ++i) {
        for (int icut = 0; icut < ncut+1; ++icut) {
            chains[i] = new TChain("MyLCTuple",classnames[i]); 
            
            TString hname = "h_Mrecoil_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Mrecoil[i][icut] = new TH1F(hname,var, 40, 300, 500);
            //h_Mrecoil[i][icut]->Sumw2();
            h_Mrecoil[i][icut]->StatOverflows(true);

            hname = "h_EboostC_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EboostC[i][icut] = new TH1F(hname,var, 150, 0, 15);
            //h_Eboost[i][icut]->Sumw2();
            h_EboostC[i][icut]->StatOverflows(true);

            hname = "h_EboostC_log_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EboostC_log[i][icut] = new TH1F(hname,var, 80, -2, 2);
            //h_Eboost[i][icut]->Sumw2();
            h_EboostC_log[i][icut]->StatOverflows(true);
            
            hname = "h_EboostN_log_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
	    cout << "booking histogram " << hname << endl;
            h_EboostN_log[i][icut] = new TH1F(hname,var, 80, -2, 2);
            //h_Eboost[i][icut]->Sumw2();
             h_EboostN_log[i][icut]->StatOverflows(true);

            hname = "h_EboostN_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EboostN[i][icut] = new TH1F(hname,var, 100, 0, 25);
            // h_EboostN[i][icut]->Sumw2();
            h_EboostN[i][icut]->StatOverflows(true);
            
            hname = "h_EboostC_Mreccut_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EboostC_Mreccut[i][icut] = new TH1F(hname,var, 25, 0, 2.5);
            //h_Eboost2[i][icut]->Sumw2();
            h_EboostC_Mreccut[i][icut]->StatOverflows(true);
            
            hname = "h_EboostN_Mreccut_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EboostN_Mreccut[i][icut] = new TH1F(hname,var, 25, 0, 2.5);
            //h_Eboost2[i][icut]->Sumw2();
            h_EboostN_Mreccut[i][icut]->StatOverflows(true);
            
            hname = "h_2dC_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_2dC[i][icut] = new TH2F(hname,"", 100, 300, 500, 30, 0, 3);
            //h_2d[i][icut]->Sumw2();
            h_2dC[i][icut]->StatOverflows(true);
                    
            hname = "h_2dN_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_2dN[i][icut] = new TH2F(hname,"", 100, 300, 500, 50, 0, 10);
            //h_2d[i][icut]->Sumw2();
            h_2dN[i][icut]->StatOverflows(true);
            
            hname = "h_Egmax_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_Egmax[i][icut]= new TH1F(hname,var, 100, 0, 250);
            //h_Egmax[i][icut]->Sumw2();
            h_Egmax[i][icut]->StatOverflows(true);
            
            hname = "h_Nrecop_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_Nrecop[i][icut]= new TH1F(hname,var, 20, 0, 20);
            //h_Egmax[i][icut]->Sumw2();
            h_Nrecop[i][icut]->StatOverflows(true);

            hname = "h_Nrecop1_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Nrecop1[i][icut]= new TH1F(hname,var, 50, 0, 50);
            //h_Egmax[i][icut]->Sumw2();
            h_Nrecop1[i][icut]->StatOverflows(true);
    
            hname = "h_Evis_Pandora_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Evis_Pandora[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Egmax[i][icut]->Sumw2();
            h_Evis_Pandora[i][icut]->StatOverflows(true);
            
	    hname = "h_Evis_PandBeam_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Evis_PandBeam[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Egmax[i][icut]->Sumw2();
            h_Evis_PandBeam[i][icut]->StatOverflows(true);

            
	    hname = "h_Evis_vPandBeam_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Evis_vPandBeam[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Egmax[i][icut]->Sumw2();
            h_Evis_vPandBeam[i][icut]->StatOverflows(true);


	    hname = "h_Ptvis_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Ptvis[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Ptvis[i][icut]->Sumw2();
            h_Ptvis[i][icut]->StatOverflows(true);

            hname = "h_Emiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_Emiss[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Egmax[i][icut]->Sumw2();
            h_Emiss[i][icut]->StatOverflows(true);
            
            hname = "h_Emiss2_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_Emiss2[i][icut]= new TH1F(hname,var, 40, 300, 500);
            //h_Egmax[i][icut]->Sumw2();
            h_Emiss2[i][icut]->StatOverflows(true);
	    
	    hname = "h_Ptmiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Ptmiss[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Ptmiss[i][icut]->Sumw2();
            h_Ptmiss[i][icut]->StatOverflows(true);

	    hname = "h_Pzmiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Pzmiss[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_Pzmiss[i][icut]->Sumw2();
            h_Pzmiss[i][icut]->StatOverflows(true);

            hname = "h_2dmiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_2dmiss[i][icut] = new TH2F(hname,"", 36, 0, 360, 24, 0, 12);
            //h_2dmiss[i][icut]->Sumw2();
            h_2dmiss[i][icut]->StatOverflows(true);

	    hname = "h_2dmissP_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_2dmissP[i][icut] = new TH2F(hname,"", 36, 0, 360, 24, 0, 12);
            //h_2dmiss[i][icut]->Sumw2();
            h_2dmissP[i][icut]->StatOverflows(true);


	    hname = "h_2dmiss2_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_2dmiss2[i][icut] = new TH2F(hname,"", 36, 0, 360, 50, 0, 500);
            //h_2dmiss[i][icut]->Sumw2();
            h_2dmiss2[i][icut]->StatOverflows(true);


	    hname = "h_Cosgmax_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_Cosgmax[i][icut]= new TH1F(hname,var, 100, -1, +1);
            //h_Egmax[i][icut]->Sumw2();
            h_Cosgmax[i][icut]->StatOverflows(true);
            
	    hname = "h_Cosother_";
	    hname.Append(classnames[i]);
	    hname.Append("_");
	    hname.Append(cutnames[icut]);	    
	    cout << "booking histogram " << hname << endl;
	    h_Cosother[i][icut]= new TH1F(hname,var, 100, -1, 1);
	    //h_Egmax[i][icut]->Sumw2();
	    h_Cosother[i][icut]->StatOverflows(true);
            
	    hname = "h_Ptother_";
	    hname.Append(classnames[i]);
	    hname.Append("_");
	    hname.Append(cutnames[icut]);	    
    	    cout << "booking histogram " << hname << endl;
	    h_Ptother[i][icut]= new TH1F(hname,var, 100, 0, 10);
	    //h_Egmax[i][icut]->Sumw2();
	    h_Ptother[i][icut]->StatOverflows(true);

	    hname = "h_Ptother2_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Ptother2[i][icut]= new TH1F(hname,var, 60, 0, 3);
            //h_Egmax[i][icut]->Sumw2();
            h_Ptother2[i][icut]->StatOverflows(true);    

	    hname = "h_Phimiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Phimiss[i][icut]= new TH1F(hname,var, 180, 0, 360);
            //h_Egmax[i][icut]->Sumw2();
            h_Phimiss[i][icut]->StatOverflows(true);
    
	    hname = "h_Phiother_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Phiother[i][icut]= new TH1F(hname,var, 180, 0, 360);
            //h_Egmax[i][icut]->Sumw2();
            h_Phiother[i][icut]->StatOverflows(true);

	    hname = "h_Thetaother_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Thetaother[i][icut]= new TH1F(hname,var, 180, -90, 90);
            //h_Egmax[i][icut]->Sumw2();
            h_Thetaother[i][icut]->StatOverflows(true);

	    hname = "h_Etaother_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_Etaother[i][icut]= new TH1F(hname,var, 40, 0, 5);
            //h_Egmax[i][icut]->Sumw2();
            h_Etaother[i][icut]->StatOverflows(true);


	    hname = "h_NBeamCalPSeen_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_NBeamCalPSeen[i][icut]= new TH1F(hname,var, 50, 0, 5);
            //h_NBeamCalPart[i][icut]->Sumw2();
            h_NBeamCalPSeen[i][icut]->StatOverflows(true);

	    hname = "h_NBeamCalPTrue_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_NBeamCalPTrue[i][icut]= new TH1F(hname,var, 50, 0, 5);
            //h_NBeamCalPart[i][icut]->Sumw2();
            h_NBeamCalPTrue[i][icut]->StatOverflows(true);

	    hname = "h_EBeamCalPartTrue_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EBeamCalPartTrue[i][icut]= new TH1F(hname,var, 100, 0, 500);
            //h_EBeamCalPart[i][icut]->Sumw2();
            h_EBeamCalPartTrue[i][icut]->StatOverflows(true);

	    hname = "h_EBeamCalPartSeen_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EBeamCalPartSeen[i][icut]= new TH1F(hname,var, 10, 0, 50);
            //h_EBeamCalPart[i][icut]->Sumw2();
            h_EBeamCalPartSeen[i][icut]->StatOverflows(true);

	    hname = "h_EBeamCalPartSum_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_EBeamCalPartSum[i][icut]= new TH1F(hname,var, 20, 0, 100);
            //h_EBeamCalPart[i][icut]->Sumw2();
            h_EBeamCalPartSum[i][icut]->StatOverflows(true);
	    
	    hname = "h_2dBeamCal_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_2dBeamCal[i][icut] = new TH2F(hname,"", 100, 300, 500, 30, 0, 3);
            //h_2d[i][icut]->Sumw2();
            h_2dBeamCal[i][icut]->StatOverflows(true);

	    hname = "h_2dPmiss_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);	    
            cout << "booking histogram " << hname << endl;
            h_2dPmiss[i][icut] = new TH2F(hname,"", 100, 0, 500, 100, 0, 500);
            //h_2d[i][icut]->Sumw2();
            h_2dPmiss[i][icut]->StatOverflows(true);

	    hname = "h_MeanMchi_";
            hname.Append(classnames[i]);
            hname.Append("_");
            hname.Append(cutnames[icut]);
            cout << "booking histogram " << hname << endl;
            h_MeanMchi[i][icut]= new TH1F(hname,var, 20, 0, 100);
            //h_EBeamCalPart[i][icut]->Sumw2();
            h_MeanMchi[i][icut]->StatOverflows(true);

	}
	
        /* efficiency_chi[i]=0; purity_chi[i]=0;*/ Nsig_chi[i]=0; Nnosig_chi[i]=0; Nsig_chi_sel[i]=0; Nnosig_chi_sel[i]=0; /*eff_pur_chi[i]=0; efficiency_chi0[i]=0;*/ /*purity_chi0[i]=0;*/ Nsig_chi0[i]=0; Nnosig_chi0[i]=0; Nsig_chi0_sel[i]=0; Nnosig_chi0_sel[i]=0;/* eff_pur_chi0[i]=0;*/
    }
    
    // assign files to chains
    int iclass;
    for (int i = 0; i < nfilesused; ++i) {
      filenames[i] = names[i].Copy();
      filenames[i].Prepend("/scratch/hh/dust/naf/ilc/user/sert/higgsinos/ROOTs/20apr2013_trkeff_faketrk/");
      filenames[i].Append(".root");
      files[i] = new TFile(filenames[i]);
      if (filenames[i].Contains("cc11g")) iclass = 0; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g")) iclass = 1; //  "ne2ne2";
      else if (filenames[i].Contains("2f_6.root")) iclass = 2; //  "sm2f";
      else if (filenames[i].Contains("3f_6")) iclass = 3; //  "sm3f";
      else if (filenames[i].Contains("4f_6.root")) iclass = 4; //  "sm4f";
      else if (filenames[i].Contains("5f_6")) iclass = 5; //  "sm5f";
      else if (filenames[i].Contains("6f")) iclass = 6; //  "sm6f";
      else if (filenames[i].Contains("aa_2f")) iclass = 7; //  "smaa_2f";
      else if (filenames[i].Contains("aa_4f")) iclass = 8; //  "smaa_4f";
      /*
      else if (filenames[i].Contains("cc11g_chi1_167_86")) iclass = 9; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_167_86")) iclass = 10; //  "ne2ne2";
      
      else if (filenames[i].Contains("cc11g_chi1_168_36")) iclass = 11; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_168_36")) iclass = 12; //  "ne2ne2";
      else if (filenames[i].Contains("cc11g_chi1_168_86")) iclass = 13; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_168_86")) iclass = 14; //  "ne2ne2";
      
      else if (filenames[i].Contains("cc11g_chi1_169_36")) iclass = 15; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_169_36")) iclass = 16; //  "ne2ne2";
      else if (filenames[i].Contains("cc11g_chi1_169_86")) iclass = 17; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_169_86")) iclass = 18; //  "ne2ne2";
      
      else if (filenames[i].Contains("cc11g_chi1_166_36")) iclass = 19; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_166_36")) iclass = 20; //  "ne2ne2";
      else if (filenames[i].Contains("cc11g_chi1_166_86")) iclass = 21; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_166_86")) iclass = 22; //  "ne2ne2";
      
      else if (filenames[i].Contains("cc11g_chi1_165_36")) iclass = 23; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_165_36")) iclass = 24; //  "ne2ne2";
      else if (filenames[i].Contains("cc11g_chi1_165_86")) iclass = 25; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_165_86")) iclass = 26; //  "ne2ne2";
      
      else if (filenames[i].Contains("cc11g_chi1_164_86")) iclass = 27; //  "ch1ch1";
      else if (filenames[i].Contains("nn12g_chi1_164_86")) iclass = 28; //  "ne2ne2";
      */
      
      else cout << "ERROR: filename " << filenames[i] << " doesn't fit in any defined class!" << endl;
      cout << "DEBUG: filename " << filenames[i] << " sorted into class " << classnames[iclass] << endl;
      if (iclass < nclassused) chains[iclass]->Add(filenames[i]);
    }
    
    
    // weight file
    TFile *weightfile = new TFile("weighthistos_3080_250413_woanytrkeff.root");
    // list file
    TFile *listfile = new TFile("cutflowlist_sel_250413_Emiss300_walltrkeff.root");
    listfile->Print();
    
    // fill histos
    const unsigned int proclength = 100;
    TString lastproc = "";
    TString shortproc = "";
    TH1F *weighthis = 0;
    float weight = 1.;
    
    int nrc = -1;
    int nrec = -1;
    int nmcp = -1;
    int evevt =-1;

    float xsection = -1.;
    
    int Nel=0;
    int Nmu=0;
    int NpiP=0;
    int Ngall=0;
    int Ngsoft=0;	
    int Ngmax=0;
    int NkaN=0;
    int NclP=0;
    int NclN=0;
    int Ntr =0;
    
    float  Evis = 0.;
    float  Emiss = 0.;
    
    float Egmax = -1.;
    float Mrecoil = 0.;
    float EboostC = -1.;
    float EboostCXang = -1.;
    float EboostN = -1.;
    float EboostNXang = -1.;
    float Cosgmax = -2.;
    float Cosother = -2.;
    float Ptother = -1.;
    float Phiother = -1.;
    float Thetaother = -1.;
    float Etaother = -1.;
    float Pxvis = 0.;
    float Pxmiss = -1.;
    float Pyvis = 0.;
    float Pymiss = -1.;
    float Pzvis = 0.;
    float Pzmiss = -1.;
    float Phimiss = -1.;
    float Phimissing = -1.;
    float Ptmiss = -1;
    float Ptvis = -1;

    float PxmissP = -1.;
    float PymissP = -1.;
    float PzmissP = -1.;
    float PtmissP = -1;


    int NBCalPartTrue = 0;
    float NBCalPartSeen = 0;
    float EBCalPartTrueMax = 0;
    float EBCalPartSeenMax = 0;

    int Ebeamcal =0;

    float Mreccut=345.;
    float Mreccut2=343.;
  
  double NsigChi_sel, NnosigChi_sel, NsigChi, NnosigChi, efficiency_chi, purity_chi, eff_pur_chi, NsigChi0_sel, NnosigChi0_sel, NsigChi0, NnosigChi0, efficiency_chi0, purity_chi0, eff_pur_chi0;
    
    NsigChi_sel=0; NnosigChi_sel=0; NsigChi=0; NnosigChi=0; efficiency_chi=0; purity_chi=0; eff_pur_chi=0; NsigChi0_sel=0; NnosigChi0_sel=0; NsigChi0=0; NnosigChi0=0; efficiency_chi0=0; purity_chi0=0; eff_pur_chi0=0;
 
    
    const unsigned int nreco=10000;	

    float rcene[nreco];
    int rcori[nreco];
    float rcgpi[nreco];


    float Cosel[nreco];
    float Cosmu[nreco];
    float CospiP[nreco];
    float CoskaN[nreco];
    float Cosgsoft[nreco];
    
    float Eel[nreco];
    float Emu[nreco];
    float EpiP[nreco];
    float EkaN[nreco];
    float Egsoft[nreco];

    float Ptel[nreco];
    float Ptmu[nreco];
    float PtpiP[nreco];
    float PtkaN[nreco];
    float Ptgsoft[nreco];

    float Phiel[nreco];
    float Phimu[nreco];
    float PhipiP[nreco];
    float PhikaN[nreco];
    float Phigsoft[nreco];

    float Thetael[nreco];
    float Thetamu[nreco];
    float ThetapiP[nreco];
    float ThetakaN[nreco];
    float Thetagsoft[nreco];

    float Etael[nreco];
    float Etamu[nreco];
    float EtapiP[nreco];
    float EtakaN[nreco];
    float Etagsoft[nreco];

    float EBCalPartTrue[nreco] ;
    float EBCalPartSeen[nreco] ;

    //  for(int k=0; k < nreco; k++){
    // EBCalPart[nreco] =0;
    //}

  /* float Cosel[nrc];
    float Cosmu[nrc];
    float CospiP[nrc];
    float CoskaN[nrc];
    float Cosgsoft[nrc];
    
    float Ptel[nrc];
    float Ptmu[nrc];
    float PtpiP[nrc];
    float PtkaN[nrc];
    float Ptgsoft[nrc];*/


    float Meanfit_dm077=0;
    float Mean_dm077=0;
    
    
    for (int i = 0; i < nclassused; ++i) {
        chains[i]->SetBranchStatus("*",0); //disable all branches
        //    chains[i]->SetBranchAddress("evis", &evis);                     chains[i]->SetBranchStatus("evis",1); 
        
        chains[i]->SetBranchAddress("nrc", &nrc);  chains[i]->SetBranchStatus("nrc",1); 
        chains[i]->SetBranchAddress("nmcp", &nmcp);  chains[i]->SetBranchStatus("nmcp",1); 
        chains[i]->SetBranchAddress("evevt", &evevt);  chains[i]->SetBranchStatus("evevt",1); 
        chains[i]->SetBranchAddress("evpro", proc);        chains[i]->SetBranchStatus("evpro",1); 
        chains[i]->SetBranchAddress("evsig", &xsection); chains[i]->SetBranchStatus("evsig",1); 
       
	chains[i]->SetBranchAddress("rcene", rcene); chains[i]->SetBranchStatus("rcene",1);
	chains[i]->SetBranchAddress("rcori", rcori); chains[i]->SetBranchStatus("rcori",1);
	chains[i]->SetBranchAddress("rcgpi", rcgpi); chains[i]->SetBranchStatus("rcgpi",1);

	chains[i]->SetBranchAddress("Nel", &Nel);  chains[i]->SetBranchStatus("Nel",1); 
        chains[i]->SetBranchAddress("Ngsoft", &Ngsoft);  chains[i]->SetBranchStatus("Ngsoft",1); 
        chains[i]->SetBranchAddress("Nmu", &Nmu);  chains[i]->SetBranchStatus("Nmu",1); 
        chains[i]->SetBranchAddress("NpiP", &NpiP);  chains[i]->SetBranchStatus("NpiP",1); 
        chains[i]->SetBranchAddress("Ngall", &Ngall);   chains[i]->SetBranchStatus("Ngall",1);
        chains[i]->SetBranchAddress("Ngmax", &Ngmax); chains[i]->SetBranchStatus("Ngmax",1);
        chains[i]->SetBranchAddress("NkaN", &NkaN); chains[i]->SetBranchStatus("NkaN",1);
        chains[i]->SetBranchAddress("NclP", &NclP); chains[i]->SetBranchStatus("NclP",1);
        chains[i]->SetBranchAddress("NclN", &NclN); chains[i]->SetBranchStatus("NclN",1);
        chains[i]->SetBranchAddress("Ntr", &Ntr); chains[i]->SetBranchStatus("Ntr",1);
        chains[i]->SetBranchAddress("Ngmax", &Ngmax); chains[i]->SetBranchStatus("Ngmax",1);
        chains[i]->SetBranchAddress("Egmax", &Egmax); chains[i]->SetBranchStatus("Egmax",1);					    
        chains[i]->SetBranchAddress("Mrecoil", &Mrecoil); chains[i]->SetBranchStatus("Mrecoil",1);
        chains[i]->SetBranchAddress("EboostC", &EboostC); chains[i]->SetBranchStatus("EboostC",1);
        chains[i]->SetBranchAddress("EboostCXang", &EboostCXang); chains[i]->SetBranchStatus("EboostCXang",1);     
        chains[i]->SetBranchAddress("EboostN", &EboostN); chains[i]->SetBranchStatus("EboostN",1); 
        chains[i]->SetBranchAddress("EboostNXang", &EboostNXang); chains[i]->SetBranchStatus("EboostNXang",1);
        chains[i]->SetBranchAddress("Evis", &Evis); chains[i]->SetBranchStatus("Evis",1);
        chains[i]->SetBranchAddress("Emiss", &Emiss); chains[i]->SetBranchStatus("Emiss",1);
        chains[i]->SetBranchAddress("Pxvis", &Pxvis); chains[i]->SetBranchStatus("Pxvis",1);
	chains[i]->SetBranchAddress("Pyvis", &Pyvis); chains[i]->SetBranchStatus("Pyvis",1);
        chains[i]->SetBranchAddress("Pzvis", &Pzvis); chains[i]->SetBranchStatus("Pzvis",1);
	chains[i]->SetBranchAddress("Ptvis", &Ptvis); chains[i]->SetBranchStatus("Ptvis",1);
	chains[i]->SetBranchAddress("Pxmiss", &Pxmiss); chains[i]->SetBranchStatus("Pxmiss",1);
	chains[i]->SetBranchAddress("Pymiss", &Pymiss); chains[i]->SetBranchStatus("Pymiss",1);
	chains[i]->SetBranchAddress("Pzmiss", &Pzmiss); chains[i]->SetBranchStatus("Pzmiss",1);
	chains[i]->SetBranchAddress("Ptmiss", &Ptmiss); chains[i]->SetBranchStatus("Ptmiss",1);
	chains[i]->SetBranchAddress("Phimiss", &Phimiss); chains[i]->SetBranchStatus("Phimiss",1);
	chains[i]->SetBranchAddress("Cosgmax", &Cosgmax); chains[i]->SetBranchStatus("Cosgmax",1);

	chains[i]->SetBranchAddress("Cosel", Cosel); chains[i]->SetBranchStatus("Cosel",1);
	//cout << "I arrived cos!" << endl;
	//chains[i]->SetBranchStatus("Cosel",1); chains[i]->SetBranchAddress("Cosel", Cosel);
	chains[i]->SetBranchAddress("Cosmu", Cosmu); chains[i]->SetBranchStatus("Cosmu",1);
        chains[i]->SetBranchAddress("CospiP", CospiP); chains[i]->SetBranchStatus("CospiP",1);
	chains[i]->SetBranchAddress("CoskaN", CoskaN); chains[i]->SetBranchStatus("CoskaN",1);
	chains[i]->SetBranchAddress("Cosgsoft", Cosgsoft); chains[i]->SetBranchStatus("Cosgsoft",1);


	chains[i]->SetBranchAddress("Eel", Eel); chains[i]->SetBranchStatus("Eel",1);
	chains[i]->SetBranchAddress("Emu", Emu); chains[i]->SetBranchStatus("Emu",1);
	chains[i]->SetBranchAddress("EpiP", EpiP); chains[i]->SetBranchStatus("EpiP",1);
	chains[i]->SetBranchAddress("EkaN", EkaN); chains[i]->SetBranchStatus("EkaN",1);
	chains[i]->SetBranchAddress("Egsoft", Egsoft); chains[i]->SetBranchStatus("Egsoft",1);

	chains[i]->SetBranchAddress("Ptel", Ptel); chains[i]->SetBranchStatus("Ptel",1);
	chains[i]->SetBranchAddress("Ptmu", Ptmu); chains[i]->SetBranchStatus("Ptmu",1);
	chains[i]->SetBranchAddress("PtpiP", PtpiP); chains[i]->SetBranchStatus("PtpiP",1);
	chains[i]->SetBranchAddress("PtkaN", PtkaN); chains[i]->SetBranchStatus("PtkaN",1);
	chains[i]->SetBranchAddress("Ptgsoft", Ptgsoft); chains[i]->SetBranchStatus("Ptgsoft",1);
	
	chains[i]->SetBranchAddress("Phiel", Phiel); chains[i]->SetBranchStatus("Phiel",1);
        chains[i]->SetBranchAddress("Phimu", Phimu); chains[i]->SetBranchStatus("Phimu",1);
        chains[i]->SetBranchAddress("PhipiP", PhipiP); chains[i]->SetBranchStatus("PhipiP",1);
        chains[i]->SetBranchAddress("PhikaN", PhikaN); chains[i]->SetBranchStatus("PhikaN",1);
        chains[i]->SetBranchAddress("Phigsoft", Phigsoft); chains[i]->SetBranchStatus("Phigsoft",1);
	
	chains[i]->SetBranchAddress("Thetael", Thetael); chains[i]->SetBranchStatus("Thetael",1);
        chains[i]->SetBranchAddress("Thetamu", Thetamu); chains[i]->SetBranchStatus("Thetamu",1);
        chains[i]->SetBranchAddress("ThetapiP", ThetapiP); chains[i]->SetBranchStatus("ThetapiP",1);
        chains[i]->SetBranchAddress("ThetakaN", ThetakaN); chains[i]->SetBranchStatus("ThetakaN",1);
        chains[i]->SetBranchAddress("Thetagsoft", Thetagsoft); chains[i]->SetBranchStatus("Thetagsoft",1);
	
	chains[i]->SetBranchAddress("Etael", Etael); chains[i]->SetBranchStatus("Etael",1);
        chains[i]->SetBranchAddress("Etamu", Etamu); chains[i]->SetBranchStatus("Etamu",1);
        chains[i]->SetBranchAddress("EtapiP", EtapiP); chains[i]->SetBranchStatus("EtapiP",1);
        chains[i]->SetBranchAddress("EtakaN", EtakaN); chains[i]->SetBranchStatus("EtakaN",1);
        chains[i]->SetBranchAddress("Etagsoft", Etagsoft); chains[i]->SetBranchStatus("Etagsoft",1);

	chains[i]->SetBranchAddress("NBCalPartTrue", &NBCalPartTrue); chains[i]->SetBranchStatus("NBCalPartTrue",1);
	chains[i]->SetBranchAddress("NBCalPartSeen", &NBCalPartSeen); chains[i]->SetBranchStatus("NBCalPartSeen",1);
        chains[i]->SetBranchAddress("EBCalPartTrue", EBCalPartTrue); chains[i]->SetBranchStatus("EBCalPartTrue",1);
	chains[i]->SetBranchAddress("EBCalPartSeen", EBCalPartSeen); chains[i]->SetBranchStatus("EBCalPartSeen",1);
	chains[i]->SetBranchAddress("EBCalPartTrueMax", &EBCalPartTrueMax); chains[i]->SetBranchStatus("EBCalPartTrueMax",1);
        chains[i]->SetBranchAddress("EBCalPartSeenMax", &EBCalPartSeenMax); chains[i]->SetBranchStatus("EBCalPartSeenMax",1);


        for(int icut=0; icut < ncut; icut++){
            TString listname = "evtlist_";

            listname.Append(classnames[i]);
            listname.Append("_");
            listname.Append(cutnames[icut]);
            cout << "listname = " << listname << endl;
            lists[i] = (TEventList *) listfile->Get(listname);
	    // cout << "I arrived here 2!" << endl;
	    
            if (lists[i]==0) cout << "WARNING: list " << listname << " not found!" << endl;
	    //lists[i]->Print();
            chains[i]->SetEventList(lists[i]);
            int centries = chains[i]->GetEntries();
	   // cout << "centries " << centries << endl;
            int lentries = lists[i]->GetN();
	   // cout << "lentries " << lentries << endl;
            cout << "events in list for class " <<  classnames[i] << " for cut " << cutnames[icut] << " = " <<  centries << endl;
            
            
            for (int ievt = 0; ievt < lentries; ++ievt) {
	      //cout << "I am in the for loop over lentires! " << endl;
                Long64_t jevt = lists[i]->GetEntry(ievt);
		chains[i]->GetEntry(jevt);
		//cout<< "ievts: " << ievt << endl;
                //cout << "class: " << i << " cut: " << icut << " event: " << ievt << endl; // <<" chains[ i ]: " << chains[i] 
                shortproc = TString (proc);
		//cout << "shortproc: " << shortproc << endl;
		
				
                 unsigned int ipos = shortproc.Index("_500"); // keep underscore!
                 // protect against process strings without ECM!
                 if (ipos > 0 && ipos < proclength) {
                     shortproc.Resize(ipos);
                 }
		 
		 shortproc += "_"; 

                //shortproc.Re(ipos); 
                // string incl. xsection to separate different Q^2 for gammagamma etc     
                shortproc += (float) (xsection);   
               // cout << "shortproc = " << shortproc << endl;   
                shortproc.ReplaceAll(" ", 1, "", 0); 
		//cout << "shortproc, no blanks = " << shortproc << endl; 
                if (shortproc != lastproc) {
                    weighthis = (TH1F *) weightfile->Get(shortproc);
		   // cout << "entries: " << weighthis->GetEntries() << endl; 
		    weight = weighthis->GetBinContent(1);
                }
	
		       				
		//cout << " before filling histograms  " << endl;
		
                // if(ievt<10){
                //   cout << "class: " << i <<  " event: " << ievt << ", nrc: " << nrc << endl; 
                // }

		/*
		Phimiss = Phimiss*180/TMath::Pi();
		
		for(int n=0; n< nreco; n++){
                  if(n < nrc){
		    Phiel[n] = Phiel[n]*180/TMath::Pi();
		    Phimu[n] = Phimu[n]*180/TMath::Pi();
		    PhipiP[n] = PhipiP[n]*180/TMath::Pi();
		    PhikaN[n] = PhikaN[n]*180/TMath::Pi();
		    Phigsoft[n] = Phigsoft[n]*180/TMath::Pi();

		    Thetael[n] = Thetael[n]*180/TMath::Pi();
                    Thetamu[n] = Thetamu[n]*180/TMath::Pi();
                    ThetapiP[n] = ThetapiP[n]*180/TMath::Pi();
                    ThetakaN[n] = ThetakaN[n]*180/TMath::Pi();
		    Thetagsoft[n] = Thetagsoft[n]*180/TMath::Pi();
		  }		
		}	


		
		PxmissP=Pxmiss*cos(0.007)-Pzmiss*sin(0.007);
		PymissP=Pymiss;
		PzmissP=Pxmiss*sin(0.007)+Pzmiss*cos(0.007);
		PtmissP=sqrt(pow(PxmissP,2)+pow(PymissP,2));

		//cout << "sin: " << sin(0.007) << " cos(0.007): " << cos(0.007) << endl;
		//cout << "Pxmiss: " << Pxmiss << "Pzmiss: " << Pzmiss <<  " PxmissP " << PxmissP << " PzmissP " << PzmissP << endl;

		if(PxmissP >0 && PymissP >0) {
		  Phimissing = atan(PymissP / PxmissP);
		}
		if(PxmissP <0 && PymissP >0) {
		  Phimissing = TMath::Pi() + atan(PymissP / PxmissP);
		}
		if(PxmissP <0 && Pymiss <0) {
		  Phimissing = TMath::Pi() + atan(PymissP / PxmissP);
		}
		if(PxmissP >0 && PymissP <0) {
		  Phimissing = 2*TMath::Pi() + atan(PymissP / PxmissP);
		}

		Phimissing = Phimissing*180/TMath::Pi();
		*/


		//************* BEGIN  --   BeamCal weight **************
		float bcalweight=1;
		float bcalweight2=1;
		float fillweight=1;
		
		//for(int n=0; n<NBCalPartTrue; n++){
		// bcalweight2 *=(1 - rcgpi[n]);
		//  cout << "bcalweight2: " << bcalweight2 << " rcgpi: " << rcgpi[n] << endl;
		//}


		for(int n=0; n< nreco; n++){
		  if(n < nrc){
		    if(rcori[n]==4){
		    bcalweight *=(1 - rcgpi[n]);
		    // cout << "ievts: " << ievt << " nrc: " << n << " bcalweight: " << bcalweight << " rcgpi: " << rcgpi[n] << endl;
		    }
		  }
		}

		fillweight= weight * bcalweight;

		//cout << "weight: " << weight << " fillweight: " << fillweight  << endl; 


		//*************  END  --  BeamCal weight **************


		if(i==3 && icut==7){
                  cout <<" EventNumber: " << evevt << " process name: " << proc << " crossections: "  << xsection << endl;
		}

		if(i==4 && icut==7){
                  cout <<" EventNumber: " << evevt << " process name: " << proc << " crossections: "  << xsection << endl;
		}




	
		float Eelmax =0;
		float Emumax =0; 
		float EpiPmax =0;

		for(int n=0; n< nreco; n++){
		  if(n < nrc){
		    if(Eelmax < Eel[n]){
		    Eelmax = Eel[n];
		    }
		     if(Emumax < Emu[n]){
		    Emumax = Emu[n];
		    }
		     if(EpiPmax < EpiP[n]){
		    EpiPmax = EpiP[n];
		    }
		  }
		}

		

		if(((Eelmax < 5 &&  Emumax ==0)|| (Eelmax == 0 && Emumax < 5)) && EpiPmax <5){
		  
		  if(icut>5)   cout << "class "<< i  << ", Eelmax " << Eelmax << ", Emumax "  << Emumax << ", EpiPmax " <<    EpiPmax  << endl;
		


		h_Nrecop[i][icut]->Fill(nrc,fillweight);
		//cout << " after first histogram  " << endl;
                h_Nrecop1[i][icut]->Fill(nrc,fillweight);
		//cout << " after second histogram  " << endl;
		// h_Evis[i][icut]->Fill(Evis,fillweight);
		h_Ptvis[i][icut]->Fill(Ptvis,fillweight);
		h_Emiss[i][icut]->Fill(Emiss,fillweight);
		h_Emiss2[i][icut]->Fill(Emiss,fillweight);
		h_Ptmiss[i][icut]->Fill(fabs(Ptmiss),fillweight);
		h_Pzmiss[i][icut]->Fill(fabs(Pzmiss),fillweight);
		h_2dmiss[i][icut]->Fill(Phimiss,fabs(Ptmiss),fillweight);
		h_2dmiss2[i][icut]->Fill(Phimiss,fabs(Ptmiss),fillweight);
		h_2dmissP[i][icut]->Fill(Phimissing,fabs(PtmissP),fillweight);
		h_Egmax[i][icut]->Fill(Egmax,fillweight);
                h_Cosgmax[i][icut]->Fill(Cosgmax,fillweight);
                h_Mrecoil[i][icut]->Fill(Mrecoil,fillweight);
                h_EboostC[i][icut]->Fill(EboostC,fillweight);
                h_EboostN[i][icut]->Fill(EboostC,fillweight);
                h_EboostC_log[i][icut]->Fill(log10(EboostC),fillweight);
                h_EboostN_log[i][icut]->Fill(log10(EboostN),fillweight);
                if(Mrecoil < Mreccut) h_EboostC_Mreccut[i][icut]->Fill(EboostC,fillweight);
                if(Mrecoil < Mreccut2) h_EboostN_Mreccut[i][icut]->Fill(EboostC,fillweight);
                h_2dC[i][icut]->Fill(Mrecoil,EboostC,fillweight);
                h_2dN[i][icut]->Fill(Mrecoil,EboostN,fillweight); 

		h_NBeamCalPTrue[i][icut]->Fill(NBCalPartTrue,fillweight);
		h_NBeamCalPSeen[i][icut]->Fill(NBCalPartSeen,fillweight);

		h_2dPmiss[i][icut]->Fill(Ptmiss, Pzmiss, fillweight);
		h_Phimiss[i][icut]->Fill(Phimiss,fillweight);
		//cout << "Nbeamcalseen: " << NBCalPartSeen << "  Nbeamcaltrue: " << NBCalPartTrue << endl;

		  
		}	


	//****************  Mean Value calculation for Eboost


	
	  /*	if(icut==7){
	 Mean_dm077= h_EboostC_Mreccut[i][icut]->GetMean();
	 cout<< "mean value of Eboost: " << Mean_dm077 << endl;
	          

        h_EboostC_Mreccut[i][icut]->Fit("gaus");
	
	TF1 *fitResult = h_EboostC_Mreccut[i][icut]->GetFunction("gaus");
	Meanfit_dm077 = fitResult->GetParameter(1);
	//fitResult->GetParameter(1);
	
	cout << "parameter1: " <<  Meanfit_dm077 << " parameter2: " << fitResult->GetParameter(2) <<" parameter3: " <<  fitResult->GetParameter(3) <<endl;

	//h_MeanMchi[i][icut]->Fill(Meanfit, fillweight);

	}*/
	  

	//**************  end of the Mean value calculation



		float  Evis_Pandora=0;
		float EBCalPartSum=0;
		
		TLorentzVector vPvis;

		vPvis.SetPxPyPzE(Pxvis,Pyvis,Pzvis,Evis);
		

	     	for(int n=0; n< nreco; n++){
		  if(n < nrc){
		
		    //  cout<< "rcori[n]:" << rcori[n]  << endl; 	  
		    
		    //if(NBCalPartTrue==5 ) cout << "Nbea,part: " << NBCalPartTrue <<" Ebeamca; " << EBCalPart[n] << " Energy: " << rcene[n] << " Ebeamcal: " << Ebeamcal << endl;
		    //    cout<< "rcori: " << rcori[n] << " NBeamCalPart: " << NBeamCalPart  << " rcene: " << rcene[n] << " rcgpi: " << rcgpi[n] <<endl;
			    
		    // cout<< "class: " << i << " cut: " << icut << " event: " << ievt << ", nrc: " << nrc <<  ", nreco: " << n << " cosel[n]:" << Cosel[n] << " cosmu[n]:" << Cosmu[n] << " cospi[n]:" << CospiP[n]  << " cosgsoft[n]:"  Cosgsoft[n]  << " coskaN[n]:" << CoskaN[n]  << endl;
		   
		
  
		    if(rcori[n]==0){
		      Evis_Pandora  += rcene[n];
		      }
		    
		    h_2dBeamCal[i][icut]->Fill(EBCalPartTrue[n],rcgpi[n],fillweight);
			       
		    h_EBeamCalPartTrue[i][icut]->Fill(EBCalPartTrue[n],fillweight);
		    if(Cosel[n]!=-2) h_Cosother[i][icut]->Fill(Cosel[n],fillweight);
		    if(Cosmu[n]!=-2) h_Cosother[i][icut]->Fill(Cosmu[n],fillweight);
                    if(CospiP[n]!=-2) h_Cosother[i][icut]->Fill(CospiP[n],fillweight);
                    if(CoskaN[n]!=-2) h_Cosother[i][icut]->Fill(CoskaN[n],fillweight);
                    if(Cosgsoft[n]!=-2) h_Cosother[i][icut]->Fill(Cosgsoft[n],fillweight);
		    
		    if(Ptel[n]!=0) h_Ptother[i][icut]->Fill(Ptel[n],fillweight);
                    if(Ptmu[n]!=0) h_Ptother[i][icut]->Fill(Ptmu[n],fillweight);
                    if(PtpiP[n]!=0) h_Ptother[i][icut]->Fill(PtpiP[n],fillweight);
                    if(PtkaN[n]!=0) h_Ptother[i][icut]->Fill(PtkaN[n],fillweight);
                    if(Ptgsoft[n]!=0) h_Ptother[i][icut]->Fill(Ptgsoft[n],fillweight);  
		    if(Ptel[n]!=0) h_Ptother2[i][icut]->Fill(Ptel[n],fillweight);
                    if(Ptmu[n]!=0) h_Ptother2[i][icut]->Fill(Ptmu[n],fillweight);
                    if(PtpiP[n]!=0) h_Ptother2[i][icut]->Fill(PtpiP[n],fillweight);
                    if(PtkaN[n]!=0) h_Ptother2[i][icut]->Fill(PtkaN[n],fillweight);
		    
		    if(Phiel[n]!=0) h_Phiother[i][icut]->Fill(Phiel[n],fillweight);
                    if(Phimu[n]!=0) h_Phiother[i][icut]->Fill(Phimu[n],fillweight);
                    if(PhipiP[n]!=0) h_Phiother[i][icut]->Fill(PhipiP[n],fillweight);
                    if(PhikaN[n]!=0) h_Phiother[i][icut]->Fill(PhikaN[n],fillweight);
                    if(Phigsoft[n]!=0) h_Phiother[i][icut]->Fill(Phigsoft[n],fillweight);

		    if(Thetael[n]!=0) h_Thetaother[i][icut]->Fill(Thetael[n],fillweight);
                    if(Thetamu[n]!=0) h_Thetaother[i][icut]->Fill(Thetamu[n],fillweight);
                    if(ThetapiP[n]!=0) h_Thetaother[i][icut]->Fill(ThetapiP[n],fillweight);
                    if(ThetakaN[n]!=0) h_Thetaother[i][icut]->Fill(ThetakaN[n],fillweight);
                    if(Thetagsoft[n]!=0) h_Thetaother[i][icut]->Fill(Thetagsoft[n],fillweight);

		    if(Etael[n]!=0) h_Etaother[i][icut]->Fill(Etael[n],fillweight);
                    if(Etamu[n]!=0) h_Etaother[i][icut]->Fill(Etamu[n],fillweight);
                    if(EtapiP[n]!=0) h_Etaother[i][icut]->Fill(EtapiP[n],fillweight);
                    if(EtakaN[n]!=0) h_Etaother[i][icut]->Fill(EtakaN[n],fillweight);
                    if(Etagsoft[n]!=0) h_Etaother[i][icut]->Fill(Etagsoft[n],fillweight);
		  }
		}
		
		
		//h_EBeamCalPartSum[i][icut]->Fill(EBCalPartSum,weight);
 

		h_Evis_Pandora[i][icut]->Fill(Evis_Pandora,fillweight);
		h_Evis_PandBeam[i][icut]->Fill(Evis,fillweight); 
		h_Evis_vPandBeam[i][icut]->Fill(vPvis.M(),fillweight); 
		  
	    
		

		

                //  //photon
                //              //if(Nel==0 && Nmu==0 && NpiP==0 && NkaN==0){
                //   //::cout << " Ngall: " << Ngall << "Ne: " << Nel << " Nmu: " << Nmu << " Npi: " << NpiP << " Nkaon: " << NkaN << std::endl; }
		//cout << "I am in the between filling histograms! " << endl;

		
               if (icut == ncut-3){
                    if(Ngmax==1 && Ngsoft == 1  && Nel==0 && Nmu==0 && NpiP==0 && NkaN==0){

		      h_Nrecop[i][icut+3]->Fill(nrc,fillweight);
		      h_Nrecop1[i][icut+3]->Fill(nrc,fillweight);
		      // h_Evis[i][icut+3]->Fill(Evis,fillweight);
		      h_Ptvis[i][icut+3]->Fill(Ptvis,fillweight);
		      h_Emiss[i][icut+3]->Fill(Emiss,fillweight);
		      h_Emiss2[i][icut+3]->Fill(Emiss,fillweight);
		      h_Ptmiss[i][icut+3]->Fill(fabs(Ptmiss),fillweight);
		      h_Pzmiss[i][icut+3]->Fill(fabs(Pzmiss),fillweight);
		      h_2dmiss[i][icut+3]->Fill(Phimiss,fabs(Ptmiss),fillweight);
		      h_2dmiss2[i][icut+3]->Fill(Phimiss,fabs(Ptmiss),fillweight);
		      h_2dmissP[i][icut+3]->Fill(Phimissing,fabs(PtmissP),fillweight);
		      h_Egmax[i][icut+3]->Fill(Egmax,fillweight);
		      h_Cosgmax[i][icut+3]->Fill(Cosgmax,fillweight);
		      h_Mrecoil[i][icut+3]->Fill(Mrecoil,fillweight);
		      h_EboostC[i][icut+3]->Fill(EboostC,fillweight);
		      h_EboostN[i][icut+3]->Fill(EboostC,fillweight);
		      h_EboostC_log[i][icut+3]->Fill(log10(EboostC),fillweight);
		      h_EboostN_log[i][icut+3]->Fill(log10(EboostN),fillweight);
		      if(Mrecoil < Mreccut) h_EboostC_Mreccut[i][icut+3]->Fill(EboostC,fillweight);
		      if(Mrecoil < Mreccut) h_EboostN_Mreccut[i][icut+3]->Fill(EboostN,fillweight);
		      h_2dC[i][icut+3]->Fill(Mrecoil,EboostC,fillweight);
		      h_2dN[i][icut+3]->Fill(Mrecoil,EboostN,fillweight); 
		      
		      h_NBeamCalPTrue[i][icut+3]->Fill(NBCalPartTrue,fillweight);
		      h_NBeamCalPSeen[i][icut+3]->Fill(NBCalPartSeen,fillweight);
		      
		      h_2dPmiss[i][icut+3]->Fill(Ptmiss, Pzmiss, fillweight);
		      h_Phimiss[i][icut+3]->Fill(Phimiss,fillweight);
		      //cout << "Nbeamcalseen: " << NBCalPartSeen << "  Nbeamcaltrue: " << NBCalPartTrue << endl;

		      
		      for(int n=0; n< nreco; n++){
			if(n < nrc){
			  
			  if(rcori[n]==0){
			    Evis_Pandora  += rcene[n];
			  }
			  
		      h_2dBeamCal[i][icut+3]->Fill(EBCalPartTrue[n],rcgpi[n],fillweight);
		      
		      h_EBeamCalPartTrue[i][icut]->Fill(EBCalPartTrue[n],fillweight);
		      if(Cosel[n]!=-2) h_Cosother[i][icut+3]->Fill(Cosel[n],fillweight);
		      if(Cosmu[n]!=-2) h_Cosother[i][icut+3]->Fill(Cosmu[n],fillweight);
		      if(CospiP[n]!=-2) h_Cosother[i][icut+3]->Fill(CospiP[n],fillweight);
		      if(CoskaN[n]!=-2) h_Cosother[i][icut+3]->Fill(CoskaN[n],fillweight);
		      if(Cosgsoft[n]!=-2) h_Cosother[i][icut+3]->Fill(Cosgsoft[n],fillweight);
		      
		      if(Ptel[n]!=0) h_Ptother[i][icut+3]->Fill(Ptel[n],fillweight);
		      if(Ptmu[n]!=0) h_Ptother[i][icut+3]->Fill(Ptmu[n],fillweight);
		      if(PtpiP[n]!=0) h_Ptother[i][icut+3]->Fill(PtpiP[n],fillweight);
		      if(PtkaN[n]!=0) h_Ptother[i][icut+3]->Fill(PtkaN[n],fillweight);
		      if(Ptgsoft[n]!=0) h_Ptother[i][icut+3]->Fill(Ptgsoft[n],fillweight);  
		      if(Ptel[n]!=0) h_Ptother2[i][icut+3]->Fill(Ptel[n],fillweight);
		      if(Ptmu[n]!=0) h_Ptother2[i][icut+3]->Fill(Ptmu[n],fillweight);
		      if(PtpiP[n]!=0) h_Ptother2[i][icut+3]->Fill(PtpiP[n],fillweight);
		      if(PtkaN[n]!=0) h_Ptother2[i][icut+3]->Fill(PtkaN[n],fillweight);
		      
		      if(Phiel[n]!=0) h_Phiother[i][icut+3]->Fill(Phiel[n],fillweight);
		      if(Phimu[n]!=0) h_Phiother[i][icut+3]->Fill(Phimu[n],fillweight);
		      if(PhipiP[n]!=0) h_Phiother[i][icut+3]->Fill(PhipiP[n],fillweight);
		      if(PhikaN[n]!=0) h_Phiother[i][icut+3]->Fill(PhikaN[n],fillweight);
		      if(Phigsoft[n]!=0) h_Phiother[i][icut+3]->Fill(Phigsoft[n],fillweight);
		      
		      if(Thetael[n]!=0) h_Thetaother[i][icut+3]->Fill(Thetael[n],fillweight);
		      if(Thetamu[n]!=0) h_Thetaother[i][icut+3]->Fill(Thetamu[n],fillweight);
		      if(ThetapiP[n]!=0) h_Thetaother[i][icut+3]->Fill(ThetapiP[n],fillweight);
		      if(ThetakaN[n]!=0) h_Thetaother[i][icut+3]->Fill(ThetakaN[n],fillweight);
		      if(Thetagsoft[n]!=0) h_Thetaother[i][icut+3]->Fill(Thetagsoft[n],fillweight);
		      
		      if(Etael[n]!=0) h_Etaother[i][icut+3]->Fill(Etael[n],fillweight);
		      if(Etamu[n]!=0) h_Etaother[i][icut+3]->Fill(Etamu[n],fillweight);
		      if(EtapiP[n]!=0) h_Etaother[i][icut+3]->Fill(EtapiP[n],fillweight);
		      if(EtakaN[n]!=0) h_Etaother[i][icut+3]->Fill(EtakaN[n],fillweight);
		      if(Etagsoft[n]!=0) h_Etaother[i][icut+3]->Fill(Etagsoft[n],fillweight);
			}
		      }
		      
		      h_Evis_Pandora[i][icut+3]->Fill(Evis_Pandora,fillweight);
		      h_Evis_PandBeam[i][icut+3]->Fill(Evis,fillweight); 
		      h_Evis_vPandBeam[i][icut+3]->Fill(vPvis.M(),fillweight); 
		    }
	       }
	       
	       
	       
	    }  //  for (int ievt = 0; ievt < lentries; ++ievt)
            
	    	    
	    
            cout << " Nentries: "<< h_Mrecoil[i][icut]->GetEntries() << endl;
            cout << "Integral: " << h_Mrecoil[i][icut]->Integral() << endl;   
            efficiency_chi = h_Mrecoil[i][icut]->GetEntries()/h_Mrecoil[i][0]->GetEntries(); 	      //eff=N_selected/N_all
            //  cout<< "=====================================================================================================" << endl;
            //cout  << "efficiency_chi: "  << efficiency_chi  << endl;
            //cout<< "=====================================================================================================" << endl;
            
           // cout <<"class: " << classnames[i] << " cuts: " << cutnames[icut] << " I am almost at the end of the code" << endl;
           
	    float effi = 0.;
            double stat0[4] = {0.,0.,0.,0.};
            double stat[4] = {0.,0.,0.,0.};	
            h_Mrecoil[i][0]->GetStats(stat0);
            h_Mrecoil[i][icut]->GetStats(stat);
            if (stat0[0] > 0) {
                effi = stat[0]/stat0[0];
                cout << "Lumi & Pol & BCal weighted events after cut " << cutnames[icut] << ": " << stat[0]
                     << ", efficiency = " << effi << ", efficiency for pi + e/mu events = " << effi/(2*0.6097*(0.1405+0.1397))<< endl;
            }
            else {
                cout << "Lumi & Pol & BCal weighted events after cut " << cutnames[icut] << ": " << stat[0]
                     << " events without cut = " << stat0[0]  << endl;
            }


        } //  for (int icut=0; icut < ncut; icut++)
        
        
    }  // for (int i = 0; i < nclassused; ++i)
    
    cout << "FINISHED FILLING HISTOGRAMS!" << endl;

    
    TFile outfile("histos_noSumw2_250413_weight_all_polP30M80_Emiss300_walltrkeff.root","RECREATE");
    for (int i = 0; i < nclassused; ++i) {
        for (int icut = 0; icut < ncut+1; ++icut) {
            h_EboostC[i][icut]->Write();
            h_EboostC_log[i][icut]->Write();
            h_EboostN[i][icut]->Write();
            h_EboostN_log[i][icut]->Write();
            h_EboostC_Mreccut[i][icut]->Write();
            h_EboostN_Mreccut[i][icut]->Write();
            h_Mrecoil[i][icut]->Write();
            h_2dC[i][icut]->Write();
            h_2dN[i][icut]->Write();
            h_Egmax[i][icut]->Write();
            h_Nrecop[i][icut]->Write();
            h_Nrecop1[i][icut]->Write();
            h_Evis_Pandora[i][icut]->Write();
	    h_Evis_PandBeam[i][icut]->Write();
	    h_Evis_vPandBeam[i][icut]->Write();
	    h_Ptvis[i][icut]->Write();
	    h_Emiss[i][icut]->Write();
	    h_Emiss2[i][icut]->Write();
	    h_Ptmiss[i][icut]->Write();
	    h_Pzmiss[i][icut]->Write();
	    h_2dmiss[i][icut]->Write();
	    h_2dmiss2[i][icut]->Write();
	    h_2dmissP[i][icut]->Write();
	    h_Cosgmax[i][icut]->Write();
            h_Cosother[i][icut]->Write();
            h_Ptother[i][icut]->Write();
	    h_Ptother2[i][icut]->Write();
	    h_NBeamCalPTrue[i][icut]->Write();
	    h_NBeamCalPSeen[i][icut]->Write();
	    h_EBeamCalPartTrue[i][icut]->Write();
	    // h_EBeamCalPartSum[i][icut]->Write();
	    h_2dPmiss[i][icut]->Write();

	    h_Phimiss[i][icut]->Write();
	    h_Phiother[i][icut]->Write();
	    h_Thetaother[i][icut]->Write();
	    h_Etaother[i][icut]->Write();
	}
        
    }
    
    cout << "FINISHED WRITING HISTOGRAMS!" << endl;
    
    return;
    

}
