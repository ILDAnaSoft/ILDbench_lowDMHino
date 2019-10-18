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



float calc_dist(Group a1, Group a2){       //function to calculate distance between two tracks 
       float distance;
       distance = (a1.var-a2.var)/sqrt((a1.err * a1.err)+(a2.err * a2.err));
       return distance;
}


float calc_avgpos(Group b1, Group b2){       //function to calculate average position of two
       float avg_pos;
       avg_pos=((b1.var/(b1.err * b1.err)) + (b2.var/(b2.err * b2.err)))/((1/(b1.err*b1.err))+(1/(b2.err*b2.err)) ); 
       return avg_pos;
}


float calc_avgerr(Group c1, Group c2){
       float avg_err;
       avg_err=sqrt(1/((1/(c1.err*c1.err))+(1/(c2.err*c2.err)) ));           //calculate avg error
       return avg_err;
}


void algo_comp_770()
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
       if (!f) {
	     
	      f = new TFile("/afs/desy.de/user/s/swathi/my_nafhh/central_files/rec/root_files/dm770_merged_overlay.root");
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
      
       TH1F *h2 =new TH1F("mcvtz Vs Groups>>h2","",4,0,4);
       TH1F *h =new TH1F("mcvtz Vs Groups>>h2","",8,0,5);
    
       const char *binlabels[3]={"sig","bkg","mix"};
       for(int i=1;i<4;i++) {
	      h2->GetXaxis()->SetBinLabel(i,binlabels[i-1]);

   }



       int k_mix=0,k_oly=0,k_sig=0;
       float distance=0.0,avg_pos=0.0,avg_err=0.0;
       int event=0,ev_n=0;
       int nevent = MyLCTuple->GetEntries();
      std::vector<Group> Z0;
     
       std::vector< pair <float,float> > Dist,D0;
       std::vector<float>val_z,error_z,dis,index,sig_d,val,big_d0,tmp_vtx;
       std::vector<float> vtx,tmp,tmp1,tmp2,avg_val,trk1,trk2,p1,p2;
       std::vector<vector<float> >  grp, vtx_counter;

      
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
	      sig_d.clear();
	      big_d0.clear();
	      D0.clear();
	      val.clear();
	    
	      int n=0,t=0,isr=0;
	      vtx_num=0;
	      ch_num=0;
	      total_vtx=0;

	      for(int k=0; k < m2tnrel; k++){    // selecting events having atleast 2 tracks reconstructed
		   
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

	      
		  
		   
	      if(ntrk < 15 && n > 0 && t > 0 ){   // events with no.of tracks less than 15 and min two tracks recontructed           
		     for(int x=0; x < m2tnrel; x++ ){  // removing pair background 
			   
			    if(m2tw[x] > 0.2){
				   int sim=mcsst[m2tf[x]];
				   int i = trsip[m2tt[x]] ;
				  
				   if(abs(mcpdg[m2tf[x]])==11 && sim & (0x1<<23) && mcpa0[m2tf[x]]==-1) {

				
				   }
				   else{		
					  if(abs(tszze[i])< 15 ){     // to find the track with highest d0 value  
						 sig_d.push_back(abs(tsdze[i]/sqrt(tscov[i][0])));
						 val.push_back(tszze[i]);
					  }
				   } 
			    } 
		     }         
		     

		     if(val.size()>0){	//to fill in the z0 value and z0 error values excluding the track with highest d0 value
  
			    for (int i=0; i<sig_d.size(); i++){

				   D0.push_back( make_pair(sig_d[i],val[i]) );  
			    }
			    sort(D0.begin(),D0.end());
			    reverse(D0.begin(),D0.end()); //sorting

			    for(int x=0; x < m2tnrel; x++ ){
			   
				   if(m2tw[x] > 0.2){
					  int sim=mcsst[m2tf[x]];
					  int i = trsip[m2tt[x]] ;
							       
					  if(abs(mcpdg[m2tf[x]])==11 && sim & (0x1<<23) && mcpa0[m2tf[x]]==-1) {

					
					  }
					  else{	

			   
						 if(tszze[i]!=D0[0].second){
							if(abs(tsdze[i]) < 0.3){
				
							       val_z.push_back(tszze[i]);
							       error_z.push_back(sqrt(tscov[i][9]));        //filling values
						 						
							}
						 }
						 else {
							big_d0.push_back(D0[0].second);    // filling the track with highest d0 value in another vector 
						 }

			      
			         
					  }
				   }
			    }
			 
			    if(big_d0.size()==1){
		      
				   evt_num=evt_num+1;
			    }	  
		    
		     }
	      }
			  
		    
	      else{
		     continue;
	      }


	  
	      for(int i=0; i < val_z.size(); i++){
		     Group new_group;      //filling class object
		 
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
					
					  avg_err =  calc_avgerr(Z0[Dist[0].second],Z0[Dist[0].second+1]);      //calculate avg error
					
				    
			    
					  if(Z0[Dist[0].second].origin==true && Z0[Dist[0].second+1].origin==true ){ //grouping tracks with original z0 values
						      
						 tmp.push_back(Z0[Dist[0].second].var);
						 tmp.push_back(Z0[Dist[0].second+1].var);
						     
						 grp.push_back(tmp);
						 avg_val.push_back(avg_pos);
						 tmp.clear();
		       
						 Z0.erase(Z0.begin()+Dist[0].second+1);
						 Z0.erase(Z0.begin()+Dist[0].second);
						    


					  }
					
					  else if((Z0[Dist[0].second].origin == true && Z0[Dist[0].second+1].origin == false) || (Z0[Dist[0].second].origin==false && Z0[Dist[0].second+1].origin == true)){     //grouping tracks with one original z0 value and other weighted average value  
						     
						      
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
	   
	   
	      int a,b,c;
	    
	      if(grp.size()>0 && vtx_num == 0){
		

	      }
	    
	      for(int gr=0; gr < grp.size(); gr++){       // calculating groups being completely signal,background or mixed
		     a=0;b=0;c=0;
		    
		     for(int g=0; g < grp[gr].size(); g++){
			    for(int k=0; k < m2tnrel; k++){
				   int t=trsip[m2tt[k]];
				   if(abs(grp[gr][g]- tszze[t]) < e){
					  int sim=mcsst[m2tf[k]];
					  if(sim & (0x1<<23)){
						 a=a+1;
						
						 break;
					  }
					  else if (abs(mcpdg[mcpa0[m2tf[t]]])==1000024){
						    
						 b=b+1;
						 
						 break;
					  }
					  else{
						
					  }
				   }
					 
			    }
			  

		     }
		   
		     if(a==0 && b>0){    // signal group

			    h2-> AddBinContent(1);
			    k_sig=k_sig+1;
		     }
		     else if(a>0 && b==0){    //overlay group 
			    h2-> AddBinContent(2); 
			    k_oly=k_oly+1; 
		     }
		     else if(a>0 && b > 0){   //mix group
			    k_mix=k_mix+1;
			    h2-> AddBinContent(3);  
		     }

			 
	      }
	      // } 
       }
       //	cout<<"The mix is "<<k_mix<<" the oly is "<<k_oly<<" the sig is "<<k_sig<<endl;
       //	cout<<"The events are "<<ev_n<<endl;
       TCanvas* c = new TCanvas ("c","c",800,600);
       c->cd();
    
       h2->SetLineColor(kBlack);
       h2->Draw("hist");
     
      

}
