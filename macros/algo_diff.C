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


using namespace std;
struct Group{
      float var;
      float err;
      bool origin;
      bool operator < (const  Group& grp2){
	    return var < grp2.var;
      }


};



float calc_dist(Group a1, Group a2){
       float distance;
       distance = (a1.var-a2.var)/sqrt((a1.err * a1.err)+(a2.err * a2.err));  //function to calculate distance between two tracks
       return distance;
}


float calc_avgpos(Group b1, Group b2){     //function to calculate average position of two tracks
       float avg_pos;
       avg_pos=((b1.var/(b1.err * b1.err)) + (b2.var/(b2.err * b2.err)))/((1/(b1.err*b1.err))+(1/(b2.err*b2.err)) ); 
       return avg_pos;
}


float calc_avgerr(Group c1, Group c2){
       float avg_err;
       avg_err=sqrt(1/((1/(c1.err*c1.err))+(1/(c2.err*c2.err)) ));           //calculate avg error
       return avg_err;
}

struct Vtx{
       float vtz;
       float p;
       bool operator < (const  Vtx& grp1){
	      return vtz < grp1.vtz;
       }

     
};

bool myfunction(Vtx v, Vtx v2){        //function to calculate the number of true vertices
	      return (v.vtz == v2.vtz);
       }


int calc_vtxnum(Vtx vt,Vtx vt1,vector<Vtx>tmp_vtx, vector<Vtx> tmp_vtx2, float mox[1000],float moy[1000], float moz[1000], float vtx[1000], float vty[1000], float vtz[1000], int s[1000], int pa0[1000],int gst[1000], float cha[1000], int nmcp, int pdg[1000]){
       float pt=0.0,cos_theta=0.0,d_mc=0.0;
       float e =0.000000000000000015;
       int vtx_num=0,o_vtx=0,ch_vtx=0;
       tmp_vtx.clear();
       tmp_vtx2.clear();
       Vtx vt2;

       for(int imcp=0; imcp < nmcp; imcp++){     //finding mcparticle having highest sqrt(x^2+y^2) value
	      int simstat = s[imcp] ;
	    
 
		     if(abs(cha[imcp])>0 ){
			    double p = sqrt(mox[imcp]*mox[imcp]+moy[imcp]*moy[imcp]+moz[imcp]*moz[imcp]);
			    pt=sqrt(mox[imcp]*mox[imcp]+moy[imcp]*moy[imcp]);
			    cos_theta=((moz[imcp])/(sqrt((mox[imcp]*mox[imcp])+(moy[imcp]*moy[imcp])+(moz[imcp]*moz[imcp]))));
			    if(pt > 0.1 && abs(cos_theta) < 0.99 ){
				   d_mc=sqrt((vtx[imcp]*vtx[imcp])+ (vty[imcp]*vty[imcp]));
				   if(d_mc < 0.2 && vtz[imcp] < 15.){
				 
					  if(simstat & (0x1<<23)){
						 if(vtx[pa0[imcp]]==0.0 && vty[pa0[imcp]]==0.0 && (gst[imcp]==1 || gst[imcp]==0)){
						
							vt.vtz=vtz[pa0[imcp]];
							vt.p=p;
							tmp_vtx.push_back(vt);
						 }
						 else if(vtx[pa0[pa0[imcp]]]==0.0  &&  vty[pa0[pa0[imcp]]]==0.0 && (gst[imcp]==1 || gst[imcp]==0)){

							
							vt.vtz=vtz[pa0[pa0[imcp]]];
							vt.p=p;
							tmp_vtx.push_back(vt);
						 }
					  }
					  else {
						 if(cha[imcp]!=0 && gst[imcp]==1){
						
							vt1.vtz=vtz[imcp];
							vt1.p=p;
							tmp_vtx2.push_back(vt1);
						 }
					  }

				   }
			    
		     }		      
	      }
       }
     
       std::sort(tmp_vtx.begin(),tmp_vtx.end());
       tmp_vtx.erase( unique( tmp_vtx.begin(), tmp_vtx.end(),myfunction), tmp_vtx.end() );
       int size=tmp_vtx.size();
       float sig,sig1,sig2,del_z;

       for(int i=0; i < tmp_vtx.size(); i++){     //combining overlay vertices if too close to each other
	      sig=0;
	      sig1=0;
	      sig2=0;
	      del_z=0;


	      if(i==tmp_vtx.size()-1){
		     break;
	      }
	     
	      else{
	   
		     if( 0.0 < tmp_vtx[i].p < 2.0){	    
			    sig1 = 0.15;	
		     }

		     else if( 2.0 < tmp_vtx[i].p < 4.0){	    
			    sig1 = 0.05;	
		     }
		     else if( 4.0 < tmp_vtx[i].p < 20.0){	    
			    sig1 = 0.02;	
		     }
		     else if( 20.0 < tmp_vtx[i].p < 100.0){	    
			    sig1 = 0.008;	
		     }
		     if( 0.0 < tmp_vtx[i+1].p < 2.0){	    
			    sig2 = 0.15;	
		     }

		     else if( 2.0 < tmp_vtx[i+1].p < 4.0){	    
			    sig2 = 0.05;	
		     }
		     else if( 4.0 < tmp_vtx[i+1].p < 20.0){	    
			    sig2 = 0.02;	
		     }
		     else if( 20.0 < tmp_vtx[i+1].p< 100.0){	    
			    sig2 = 0.008;	
		     }
		     sig=sqrt(sig1*sig1+sig2*sig2);
		     del_z = abs(tmp_vtx[i].vtz - tmp_vtx[i+1].vtz);

		     if(del_z < abs(sig) && size > 0){
			    size=size-1;
	      
		     }  
	      }
       }

       std::sort(tmp_vtx2.begin(),tmp_vtx2.end());
       tmp_vtx2.erase( unique( tmp_vtx2.begin(), tmp_vtx2.end(),myfunction), tmp_vtx2.end() );
       int size2=tmp_vtx2.size();

       for(int j=0; j < tmp_vtx2.size(); j++){       //combining signal vertices if too close to each other 
	      sig=0;
	      sig1=0;
	      sig2=0;
	      del_z=0;
	     

	      if(j == tmp_vtx2.size()-1){
		     break;
	      }
	      else{

		     if( 0.0 < tmp_vtx2[j].p < 2.0){	    
			    sig1 = 0.15;	
		     }

		     else if( 2.0 < tmp_vtx2[j].p < 4.0){	    
			    sig1 = 0.05;	
		     }
		     else if( 4.0 < tmp_vtx2[j].p < 20.0){	    
			    sig1 = 0.02;	
		     }
		     else if( 20.0 < tmp_vtx2[j].p < 100.0){	    
			    sig1 = 0.008;	
		     }
		     if( 0.0 < tmp_vtx2[j+1].p < 2.0){	    
			    sig2 = 0.15;	
		     }

		     else if( 2.0 < tmp_vtx2[j+1].p < 4.0){	    
			    sig2 = 0.05;	
		     }
		     else if( 4.0 < tmp_vtx2[j+1].p < 20.0){	    
			    sig2 = 0.02;	
		     }
		     else if( 20.0 < tmp_vtx2[j+1].p< 100.0){	    
			    sig2 = 0.008;	
		     }
		     sig=sqrt(sig1*sig1+sig2*sig2);
		     del_z = abs(tmp_vtx2[j].vtz - tmp_vtx2[j+1].vtz);

		     if(del_z < abs(sig)&& size2>0){
			    size2=size2-1;
	      
		     }  
	      }

       }
      
      
        vtx_num=size+size2;
       return vtx_num;
}


void algo_diff()
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

         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm1600_merged_overlay.root");
     
       if (!f) {
	       f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm1600_merged_overlay.root");
	    

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
       Float_t         rcmox[10000];
       Float_t         rcmoy[10000];
       Float_t         rcmoz[10000];
       Float_t         rcmas[10000];
       Float_t         rcene[10000];
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

       TH1F *h =new TH1F("mcvtz Vs Groups>>h","",8,-0.5,7.5);
       TH1F *h_ch =new TH1F("mcvtz Vs Groups>>h_ch","",4,0,4);
       TH1F *h_ol =new TH1F("mcvtz Vs Groups>>h_ol","",16,-0.5,20.5);
       TH2F *h2 =new TH2F("mcvtz Vs Groups>>h2","",7,-0.5,6.5,7,-0.5,6.5);
       h2 -> GetXaxis() -> SetTitle("No of mcvtx");
       h2 -> GetYaxis() -> SetTitle("No of grps");


       const char *binlabels[2]={"Sig","bkg"};
       for(int i=1;i<3;i++) {
	      h_ch->GetXaxis()->SetBinLabel(i,binlabels[i-1]);

       }



       float distance=0.0,avg_pos=0.0,avg_err=0.0;
       int event=0;
       int nevent = MyLCTuple->GetEntries();
       std::vector<Group> Z0;
       std::vector<Vtx> tmp_vtx,tmp_vtx2;
       std::vector< pair <float,float> > Dist,d0_z0;
       std::vector<float>val_z,error_z,dis,index,big_d0,big_z0;
       std::vector<float> vtx,tmp,tmp1,tmp2,avg_val,trk1,trk2,p1,p2;
       std::vector<vector<float> >  grp, vtx_counter;

       Vtx vt;
       Vtx vt1;
       int ch_num,ch=0,oly=0;
       int ev_num=0,evt_num=0;
       int vtx_num, total_vtx;
       
     
       float e =0.000000000000000015;

        for (int ievt = 0; ievt < nevent; ievt++) {
      
	      MyLCTuple->GetEntry(ievt);
	      ch_num=0;
	      event=event+1;
	       Z0.clear();
	      val_z.clear();
	      error_z.clear();
	      grp.clear();
	      Dist.clear();
	      dis.clear();
	      index.clear();
	      avg_val.clear();
	      vtx_counter.clear();
	      tmp_vtx.clear();
	      big_d0.clear();
	      big_z0.clear();
	    
	      int n=0,t=0,isr=0;
	      vtx_num=0;
	      ch_num=0;
	      total_vtx=0;

	      for(int k=0; k < m2tnrel; k++){        //selecting events with atleast 2 tracks reconstructed
		   
		     if(mcpdg[mcpa0[m2tf[k]]]==1000024){
			    n=n+1;
		     }
		     if(mcpdg[mcpa0[m2tf[k]]]== -1000024){
			    t=t+1;
		     }
		    
	      }

	      // for(int is = 0; is < nrec; is++ ){
	      // 	     if(pipdg[is] == 22){
	      // 		    if(rcene[is] >= 3){
	      // 			   isr=isr+1;	   
	      // 		    }

	      // 	     }

	      // }

	      
		  
		   
	      if(ntrk < 15 && n > 0 && t > 0 ){  // events with no.of tracks less than 15 and min two tracks recontructed           
			  
     
		     for(int x=0; x < ntrk; x++){    // to find the track with highest d0 value 
				  
			    int i = trsip[x] ;
			  
			    if(abs(tszze[i]) < 15){
				   if(abs(tsdze[i]) < 0.2){
						
					  val_z.push_back(tszze[i]);
					  error_z.push_back(sqrt(tscov[i][9]));        //filling values
						 						
				   }
			    }
			         
		     }
			
		      
		  
		     evt_num=evt_num+1;	  
		     vtx_num =calc_vtxnum( vt, vt1,tmp_vtx,tmp_vtx2,mcmox, mcmoy, mcmoz, mcvtx, mcvty, mcvtz,mcsst,mcpa0,mcgst, mccha,nmcp,mcpdg);
		     h->Fill(vtx_num);  //calling the vertex calculation function

		    
		  
	      }
			  
		    
	      else{
		     continue;
	      }


	    
	      for(int i=0; i < val_z.size(); i++){
		     Group new_group;       //filling class object
		 
		     new_group.var = val_z[i];
		     new_group.err = error_z[i];
		     new_group.origin = true;
		     Z0.push_back(new_group);
			  
			  
	      }
	   
	      

	      if(Z0.size()==1 && Z0[0].origin==true){
		     tmp.push_back(Z0[0].var);
		     grp.push_back(tmp);
		     Z0.clear();
		     tmp.clear();	  
	      }

	      else if(Z0.size()>1){
		     do
			    { 
				      
			        
				   dis.clear();
				   index.clear();
				   Dist.clear();

				   std::sort(Z0.begin(),Z0.end());

				   for(int b=0; b < Z0.size(); b++){
					  
				   }
					
				       
		    
					 for(int i=0; i < Z0.size(); i++){
						for(int j=0; j < Z0.size(); j++){
				     
						       if(i!=j){			      
						       distance = calc_dist(Z0[i],Z0[j]);
						       dis.push_back(abs(distance));
						       index.push_back(i);
						       }
						}
					 }
					 for( int v=0; v < dis.size(); v++){
						Dist.push_back(make_pair(dis[v],index[v]));
					
					 }
					 sort(Dist.begin(),Dist.end());
					 if(abs(Dist[0].first) < 1.7){
  
				
					
						avg_pos = calc_avgpos(Z0[Dist[0].second],Z0[Dist[0].second+1]);      //calculate avg position
					
						avg_err =  calc_avgerr(Z0[Dist[0].second],Z0[Dist[0].second+1]);    //calculate avg error
					
				    
			    
						if(Z0[Dist[0].second].origin==true && Z0[Dist[0].second+1].origin==true ){ //grouping tracks with original z0 values
						      
						       tmp.push_back(Z0[Dist[0].second].var);
						       tmp.push_back(Z0[Dist[0].second+1].var);
						     
						       grp.push_back(tmp);
						       avg_val.push_back(avg_pos);
						       tmp.clear();
		       
						       Z0.erase(Z0.begin()+Dist[0].second+1);
						       Z0.erase(Z0.begin()+Dist[0].second);
						    


						}
					
						else if((Z0[Dist[0].second].origin == true && Z0[Dist[0].second+1].origin == false) || (Z0[Dist[0].second].origin==false && Z0[Dist[0].second+1].origin == true)){  //grouping tracks with one original z0 value and other weighted average value
						     
						      
						       for(int av=0; av < avg_val.size(); av++){
							     
							      if(abs(avg_val[av]-Z0[Dist[0].second+1].var) < e){
								     
								     for(int n1=0; n1 < grp[av].size(); n1++){
									    tmp1.push_back(grp[av][n1]);
									   
								     } 
								     tmp1.push_back(Z0[Dist[0].second].var);
								 
								     grp.erase(grp.begin()+av);
								     avg_val.erase(avg_val.begin()+av);
								     grp.push_back(tmp1);
								     avg_val.push_back(avg_pos);
								     tmp1.clear();
								  
			     
								     Z0.erase(Z0.begin()+Dist[0].second+1);
								     Z0.erase(Z0.begin()+Dist[0].second);
								     break;

							      }
							      else if(abs(avg_val[av]-Z0[Dist[0].second].var) < e){
								    
								     for(int n2=0; n2 < grp[av].size(); n2++){
									    tmp1.push_back(grp[av][n2]);
								    
								     } 
 
								     tmp1.push_back(Z0[Dist[0].second+1].var);
								   
								     grp.erase(grp.begin()+ av);
								     avg_val.erase(avg_val.begin()+av);
								     grp.push_back(tmp1);
								     avg_val.push_back(avg_pos);
								     tmp1.clear();
								  
								     Z0.erase(Z0.begin()+Dist[0].second+1);
								     Z0.erase(Z0.begin()+Dist[0].second);
						    
								     break;
							      }

						       }
						}

						else if(Z0[Dist[0].second].origin==false && Z0[Dist[0].second+1].origin==false){
						       //grouping tracks with both weighted average value
						      
						       int a;
						       for(a=0; a < avg_val.size(); a++){
						
							      if(abs(avg_val[a]-Z0[Dist[0].second+1].var) < e){
								     for(int n3=0; n3 < grp[a].size(); n3++){
									    tmp2.push_back(grp[a][n3]);
								    
								     } 
								     
								     grp.erase(grp.begin()+ a);
								     avg_val.erase(avg_val.begin()+ a);
	
							      }
							      if(abs(avg_val[a]-Z0[Dist[0].second].var) < e){
								    
								     for(int n4=0; n4 < grp[a].size(); n4++){
									    tmp2.push_back(grp[a][n4]);
								    
								     } 
								     grp.erase(grp.begin()+ a);
								     avg_val.erase(avg_val.begin()+ a);
							      }
						       }
					 
						       Z0.erase(Z0.begin()+Dist[0].second+1);
						       Z0.erase(Z0.begin()+Dist[0].second);
				
					 
						       grp.push_back(tmp2);
						       avg_val.push_back(avg_pos);
						       tmp2.clear(); 

						}
					
					 }

					 else{
						//	cout<<"The distance is greater than 2"<<endl;
						if(Z0[Dist[0].second].origin==true && Z0[Dist[0].second+1].origin==true ){
 
						       tmp.push_back(Z0[Dist[0].second].var);
						       grp.push_back(tmp);
						       tmp.clear();
						       tmp.push_back(Z0[Dist[0].second+1].var);
						       grp.push_back(tmp);
						       tmp.clear();
						       Z0.erase(Z0.begin()+(Dist[0].second+1));
						       Z0.erase(Z0.begin()+(Dist[0].second));
				   

						}
						else if((Z0[Dist[0].second].origin == true && Z0[Dist[0].second+1].origin == false) || (Z0[Dist[0].second].origin==false && Z0[Dist[0].second+1].origin == true)){ 
						     
						       if(Z0[Dist[0].second].origin == true){
							      tmp.push_back(Z0[Dist[0].second].var);
							      grp.push_back(tmp);
					
							      Z0.erase(Z0.begin()+(Dist[0].second+1));
							      Z0.erase(Z0.begin()+(Dist[0].second));
						
							      tmp.clear();
						       }
						       else if(Z0[Dist[0].second+1].origin == true){
							      tmp.push_back(Z0[Dist[0].second+1].var);
							      grp.push_back(tmp);

					
							      Z0.erase(Z0.begin()+(Dist[0].second+1));
							      Z0.erase(Z0.begin()+(Dist[0].second));
							      tmp.clear();
						       }

						}
						else{
						      	
						       Z0.erase(Z0.begin()+(Dist[0].second+1));
						       Z0.erase(Z0.begin()+(Dist[0].second));
					  					 
						}


						if(Z0.size()>0){
						      
						       for(int z=Z0.size()-1; z >=0; z--){
							      if(Z0[z].origin == true){
								     tmp.push_back(Z0[z].var);
								     grp.push_back(tmp);
								     Z0.erase(Z0.begin()+z);
								     tmp.clear();
							      }
							      else{
								     Z0.erase(Z0.begin()+z);	 
							      }
						       }
						     
						}
				    
					 }
					 if(Z0.size()>0 ){
						      
					
						Group new_group2;
						new_group2.var = avg_pos;
						new_group2.err = avg_err;
						new_group2.origin = false;
						Z0.push_back(new_group2);
					
						     
					
					 }

				  }
		
			   while(Z0.size()!=0);
	    
		    }
	   
		 
	      if(grp.size()== vtx_num){
		    
		     ev_num=ev_num+1;
	      }
	      h2->Fill(vtx_num,grp.size());
			  
	      for(int gr=0; gr < grp.size(); gr++){
			 
		     for(int g=0; g < grp[gr].size(); g++){
			
		     }
	      }
		   
	}
     
     
     
      
       TCanvas* c = new TCanvas ("c","c",800,600);
       c->cd();
       // gPad->SetLogz(1);
       gPad->SetRightMargin(0.15);
       gStyle->SetPaintTextFormat("4.f ");
       h2->SetMarkerSize(1.5);
       h2->SetFillColor(kViolet+3);
       h2->SetLineColor(kBlack);
       h2->Draw("box");
     

}
