#include <map>
#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TString.h"
//#include <string>
#include <TChain.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TEventList.h>
#include <TCut.h>

using namespace std;

void makelists() {
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
    gStyle->SetOptStat(1111110);
    //gStyle->SetOptFit(10);
    
    cout << "DEBUG: defining cuts" << endl;
    
    // cuts
    const int ncut = 9;
    TCut *cuts[ncut];
    cuts[0]  = new TCut ("");  //no cut (hopefully!) 
    cuts[1]  = new TCut (*cuts[0]  && "EBCalPartTrueMax < 40 ");   
    cuts[2]  = new TCut (*cuts[1]  && "nrc < 15");
    cuts[3]  = new TCut (*cuts[2]  && "Egmax > 0");
    // cuts[3]  = new TCut (*cuts[2]  && "abs(Cosgmax) < 0.993 ");
    cuts[4]  = new TCut (*cuts[3]  && "abs(CosMAXel)<0.9397 && abs(CosMAXmu)<0.9397 && abs(CosMAXpiP)<0.9397 && abs(CosMAXkaN)<0.9397 && abs(CosMAXgsoft)<0.9397");
    cuts[5]  = new TCut (*cuts[4]  && "EelMax < 5  && EmuMax < 5 && EpiPMax < 5 && EkaNMax < 5 && Egsoft < 5");
    cuts[6]  = new TCut (*cuts[5]  && "Emiss > 300");
    cuts[7]  = new TCut (*cuts[6]  && "((Nel==1 && Nmu==0) || (Nmu==1 && Nel==0)) && NpiP==1 && Ngsoft==0 && NkaN==0");
    cuts[8]  = new TCut (*cuts[7]  && "EboostC < 3");
   

    cout << "DEBUG: defining cutnames" << endl;
    
    //TCut nisolep ("isolep==0");
    TString cutnames[ncut];
    cutnames[0] = "nocut";
    cutnames[1] = "Ebeamcal";    
    cutnames[2] = "nrecopart";
    cutnames[3] = "ISRgamma";
    //cutnames[3] = "costheta_isr";
    cutnames[4] = "costheta";
    cutnames[5] = "Emiss";
    cutnames[6] = "Selection_1pisemihad";
    cutnames[7] = "EboostC";
    cutnames[8] = "Etrack";
    
    const int nfiles = 13;
    const int nprocmax = 10000; 
    int nfilesused = 13;
    
    cout << "DEBUG: defining names" << endl;
    
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
    TEventList *lists[nclass][ncut]; 
    
    cout << "DEBUG: defining classnames" << endl;
    
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

    for (int iclass = 0; iclass < nclassused; ++iclass) {
        chains[iclass] = new TChain("MyLCTuple",classnames[iclass]); 
        cout << "DEBUG: chain for class " << classnames[iclass] << " opened!" << endl;
    }
    
    // assign files to chains
    int iclass;
    for (int i = 0; i < nfilesused; ++i) {
        filenames[i] = names[i].Copy();
        filenames[i].Prepend("/scratch/hh/dust/naf/ilc/user/sert/higgsinos/ROOTs/20apr2013_trkeff_faketrk/");
        filenames[i].Append(".root");
        files[i] = new TFile (filenames[i]);
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
    
  TString listname = "";
  // open in write modeB
  TFile *listfile = new TFile("cutflowlist_sel_250413_Emiss300_ELT5.root","RECREATE");
  for (int iclass = 0; iclass < nclassused; ++iclass) {
      for (int icut = 0; icut < ncut; ++icut) {
          listname = "evtlist_";
          listname.Append(classnames[iclass]);
          listname.Append("_");
          listname.Append(cutnames[icut]);
          cout << "listname = " << listname << endl;
          lists[iclass][icut] = new TEventList(listname,listname);
          listname.Prepend(">>");
          chains[iclass]->Draw(listname, *cuts[icut]);  
          lists[iclass][icut]->Write();
          //cout << "lists[iclass][icut]: " << lists[iclass][icut]<< endl;
          int centries = chains[iclass]->GetEntries();
          int lentries = lists[iclass][icut]->GetN();
          cout << "listentries for class " <<  classnames[iclass] << ", cut " << cutnames[icut] << " = " << (float) lentries << endl;
	  cout << "chainentries for class " <<  classnames[iclass] << ", cut " << cutnames[icut] << " = " << (float) centries << endl;
          cout << "Efficiency for class " <<  classnames[iclass] << ", cut " << cutnames[icut] << " = " << (float) lentries/centries << endl;
      }
  }
  listfile->Close();
  
  for (int icut = 0; icut < ncut; ++icut) {
      //cout << " ncut-before: " << ncut << ", icut: " << icut << endl;
      delete cuts[icut];
      //cout << " ncut-after: " << ncut << ", icut: " << icut << endl;
      for (int iclass = 0; iclass < nclassused; ++iclass) {
          //cout << " nclasses-before: " << nclassused << ", iclass: " << iclass << ", icut: " << icut << ", lists[iclass][icut]: " << lists[iclass][icut]<< endl;
          //          delete lists[iclass][icut];
          //cout << " nclasses-after: " << nclassused << ", iclass: " << iclass << endl;
      }
  }
  delete listfile; 
    
  return;
}
