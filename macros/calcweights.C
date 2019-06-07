#include <iostream>
#include <map>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TString.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
  //   gROOT->SetStyle("Plain");
  //   gStyle->SetOptTitle(0);
  //   gStyle->SetHistLineWidth(4);
  //   gStyle->SetLineWidth(2);
  //   gStyle->SetCanvasBorderMode(0);
  //   gStyle->SetPadBorderMode(0);
  //   gStyle->SetPadColor(0);
  //   gStyle->SetCanvasColor(0);
  //   gStyle->SetTitleColor(1);
  //   gStyle->SetStatColor(0);
  //   gStyle->SetOptStat(10);
  //   //gStyle->SetOptFit(10);
  
  const int nfiles = 13;
  const int nprocmax = 10000; 
  //   // for P(e+) = +60%, P(e-) = -80%:
  //   //                 ep+1_em-1 , ep-1_em+1 , ep+1_em+1 , ep-1_em-1 ,  gammagamma,  e+gamma,  e-gamma
  //   float polfracts[9] = {0.72,       0.02,       0.08,        0.18,           1.,   0.8, 0.2, 0.1, 0.9};    
  // for P(e+) = +30%, P(e-) = -80%:
  //                 ep+1_em-1 , ep-1_em+1 , ep+1_em+1 , ep-1_em-1 ,  gammagamma,  e+gamma,  e-gamma
  float polfracts[9] = {0.585,      0.035,     0.065,      0.315,         1.,    0.65, 0.35, 0.1, 0.9};    
  
  
 
  TString names[nfiles];
  TString filenames[nfiles]; 
  names[0]  = "cc11g_std";
  names[1]  = "nn12g_std";
  names[2]  = "2f_6";
  /*  names[3]  = "1f_3f_6.eB";
  names[4]  = "1f_3f_6.eR";
  names[5]  = "1f_3f_6.eL";
  names[6]  = "1f_3f_6.eW";
   */
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
  
  int    iproc = 0;
  
  std::map<TString, int>  nevtmap;
  std::map<TString, int>::iterator nevtit;  
  
  std::map<TString, float> xsecmap[9];
  std::map<TString, float>::iterator xsecit;  
  
  for (int i = 0; i < nfiles; ++i) {
    filenames[i] = names[i].Copy();
    
    filenames[i].Prepend("/scratch/hh/dust/naf/ilc/user/sert/higgsinos/ROOTs/20apr2013_trkeff_faketrk/");
    filenames[i].Append(".root");
    files[i] = new TFile (filenames[i]);
    cout << "opened file :"  << filenames[i] << endl;
    trees[i] = 0;
    trees[i] = (TTree *) files[i]->Get("MyLCTuple");
    if (!trees[i]) {
      cout << "ERROR: Couldn't open tree LCTuple on file: "<< filenames[i] << endl;
      return 1; 
    }
    // now xsections
    float xsection = 0;
    float epol = 0;
    float ppol = 0;
    TString lastproc = "";
    TString strproc = "";
    TString shortproc = "";
    int lastpol = -1;
    string sprocess;
    const unsigned int proclength = 100;
    char proc[proclength];
    cout << "setting branch addresses" << endl;
    trees[i]->SetBranchAddress("evsig", &xsection);
    trees[i]->SetBranchAddress("evpoe", &epol);
    trees[i]->SetBranchAddress("evpop", &ppol);
    trees[i]->SetBranchAddress("evpro", proc);
    int entries = trees[i]->GetEntries();
    //if (entries > 5) entries = 5;
    for (int ievt = 0; ievt < entries; ++ievt) {
      // cout << " in event loop, ievt =  " << ievt << endl;
      trees[i]->GetEntry(ievt);
       //cout << "xsection " << xsection << endl;
      shortproc = TString (proc);
      
      sprocess = shortproc;
      //cout << "sprocess = " << sprocess << endl; 
      
       //unsigned int posep = sprocess.find("_e");
      // unsigned int posem = sprocess.find("_p");
      // cout << "posep =" << posep << ", posem = "  <<  posem << endl;
       //if (posem < proclength && posep < proclength) {
      // string spolep = sprocess.substr (posep+3, posem-posep-3 );
      //  string spolem = sprocess.substr (posem+3, string::npos);
       //cout << ", spolep = " << spolep << ", spolem  = "  <<  spolem << endl;
      // istringstream sspolep (spolep);
      // sspolep >> ppol;
      // istringstream sspolem (spolem);
      // sspolem >> epol;
       //cout << "ppol = " << ppol << ", epol = "  <<  epol << endl;
    //}

      /*
      //******determination of polarizations of the signals using the name of process*******
      unsigned int posep = sprocess.find("_ep");
      unsigned int posem = sprocess.find("_em");
      cout << "posep =" << posep << ", posem = "  <<  posem << endl;
      if (posem < proclength && posep < proclength) {
        string spolep = sprocess.substr (posep+3, posem-posep-3 );
        string spolem = sprocess.substr (posem+3, string::npos);
        cout << ", spolep = " << spolep << ", spolem  = "  <<  spolem << endl;
        istringstream sspolep (spolep);
        sspolep >> ppol;
        istringstream sspolem (spolem);
        sspolem >> epol;
        cout << "ppol = " << ppol << ", epol = "  <<  epol << endl;
      }
      */
      
      
      //****** To make the name of process short *******
           
      
      unsigned int ipos = shortproc.Index("_500"); // keep underscore!
      //cout << "ipos " << ipos << endl;
      // protect against process strings without ECM!
      if (ipos > 0 && ipos < proclength) {
	shortproc.Resize(ipos);
      } 
      
      //else {
      shortproc += "_"; 
      //}    
      
      // string incl. xsection to separate different Q^2 for gammagamma etc
      shortproc += (float) (xsection);     
      //cout << "shortproc = " << shortproc << endl; 
      shortproc.ReplaceAll(" ", 1, "", 0); 
      //cout << "shortproc, no blanks = " << shortproc << endl; 
      //cout << "ppol = " << ppol << ", epol = " << epol << endl; 
      // find pol index
      int index = -1;
      if (ppol ==  1.0 && epol == -1.0) {index = 0;}
      else if (ppol == -1.0 && epol ==  1.0) {index = 1;}
      else if (ppol ==  1.0 && epol ==  1.0) {index = 2;}
      else if (ppol == -1.0 && epol == -1.0) {index = 3;}
      // gammagamma
      else if (ppol ==  0.0 && epol ==  0.0) {index = 4;}
      else if (ppol ==  1.0 && epol ==  0.0) {index = 5;}
      else if (ppol == -1.0 && epol ==  0.0) {index = 6;}
      else if (ppol ==  0.0 && epol ==  1.0) {index = 7;}
      else if (ppol ==  0.0 && epol == -1.0) {index = 8;}
      else {cout << "ERROR: unknown polarisation" << endl;}
      
      // already in event count map? If not, insert, else increment by one
      nevtit = nevtmap.find(shortproc);
      if (nevtit == nevtmap.end()) {
	nevtmap.insert(pair<TString,int>(shortproc, 1)); 
      }
      else {
	nevtit->second += 1;
      }
      
      // insert into cross section map 
      // - try only if process or pol changed from last event
      if (shortproc == lastproc && index == lastpol) continue;
      cout << "new shortproc = " << shortproc << ", filling xsection map! " << endl; 
      if (index != -1) {
	xsecmap[index].insert(pair<TString,double>(shortproc, xsection)); 
      }
      lastproc = shortproc;
      lastpol = index;
    }
    
    files[i]->Close();
    cout << "finished file " << *filenames[i] << endl; 
    
  }
  
  cout << "finished ! " << endl; 
  
  // now can calculate weights for each process!!!
  // iterate over event map
  // store one histo for each process with
  // bin 1       2     3...11     12...20      21 
  //     weight, lumi, xsect[9], polfrac[9], nevt 
  TH1F *weighthis[nprocmax];
  iproc = 0;
  for (nevtit = nevtmap.begin(); nevtit != nevtmap.end(); nevtit++) {
    TString proc = (*nevtit).first;
    int nevt = (*nevtit).second;
    // find corresponding entries in xsection map
    float xsect[9] = {0.,0.,0.,0.,0.};
    float sumxsect = 0;
    weighthis[iproc] = new TH1F (proc, proc, 21, 0., 21.); 
    for (int ipol = 0; ipol < 9; ++ipol) {
      weighthis[iproc]->SetBinContent (12+ipol, polfracts[ipol]);
      xsecit = xsecmap[ipol].find (proc);
      if (xsecit != xsecmap[ipol].end()) {
	xsect[ipol] = (*xsecit).second;
	sumxsect += xsect[ipol] * polfracts[ipol];     
	cout << "process " << proc << ", sumsect " << sumxsect << endl;
	weighthis[iproc]->SetBinContent (3+ipol, xsect[ipol]);
      } 
    else {
      cout << "process " << proc << " does not exist for pol index = " << ipol << endl;
      weighthis[iproc]->SetBinContent (3+ipol, 0.);
    }  
    }
    float weight = 500 * sumxsect / nevt;
    cout << "process " << proc << " gets weight " << weight << endl;
    weighthis[iproc]->SetBinContent (1, weight);
    weighthis[iproc]->SetBinContent (2, 500.);
    weighthis[iproc]->SetBinContent (21, nevt);
    TFile outfile("weighthistos_3080_250413_woanytrkeff.root","UPDATE");
    weighthis[iproc]->Write();
    outfile.Close();
    ++iproc;
  }
  
  cout << "really finished ! " << endl; 
  
  return 0;
  
}
				
				
