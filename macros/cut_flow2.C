#include<TStyle.h>
#include<TMath.h>
#include<TH2F.h>
#include "THStack.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include<TProfile2D.h>
#include<TLorentzVector.h>
using namespace std;

void cut_flow2()
{
	gStyle->SetOptStat(0);
	gROOT->Reset();

	std::vector<std::string> filename;

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_bhabhag_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_bhabhag_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_bhabhag_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_bhabhag_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_h_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_h_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_l_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_2f_z_l_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_l_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_l_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_l_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_l_eR_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_sl_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_sl_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_sl_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sw_sl_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_l_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_l_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_l_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_l_eR_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_szeorsw_l_eL_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_szeorsw_l_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_szeorsw_l_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_szeorsw_l_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_sl_eL_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_sl_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_sl_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sze_sl_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sznu_l_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sznu_l_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sznu_sl_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_sznu_sl_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_h_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_h_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_l_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_l_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_sl_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_ww_sl_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zzorww_h_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zzorww_h_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zzorww_l_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zzorww_l_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zz_sl_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_4f_zz_sl_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eL_pR.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_cc11g_eR_pL.root");

	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_nn12g_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_np-hino-vldm_770_nn12g_eR_pL.root");


	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeee_eL_pL.root");       
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveev_eL_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeee_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveev_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeee_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveev_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeee_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveev_eR_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeell_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvelv_eL_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeell_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvelv_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeell_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvelv_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeell_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveyx_eL_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeexx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveyx_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeexx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxveyx_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeexx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvlev_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeexx_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvlev_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeyy_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvlev_eR_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeyy_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvllv_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeyy_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvllv_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeeeyy_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvlyx_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellxx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxvlyx_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellxx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxee_eL_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellxx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxee_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellxx_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxee_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellyy_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxee_eR_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellyy_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxll_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellyy_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxll_eR_pL.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eellyy_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxvv_eL_pR.root");                
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveev_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxvv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveev_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxxx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveev_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxxxx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveev_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxyev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevelv_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxyev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevelv_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxyev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevelv_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxylv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevelv_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxylv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveyx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxyyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveyx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_xxxyyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveyx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yycyyu_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eeveyx_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yycyyu_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlev_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyuyyc_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlev_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyuyyc_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlev_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyuyyu_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlev_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyuyyu_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevllv_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveev_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevllv_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevllv_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevllv_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlyx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvelv_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlyx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvelv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlyx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvelv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eevlyx_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveyx_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyev_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyev_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyveyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyev_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvlev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyev_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvlev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexylv_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvlev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexylv_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvllv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexylv_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvllv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexylv_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvlyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyyx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyvlyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyyx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyxyev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyyx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyxyev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_eexyyx_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyxyev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllee_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyxylv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllee_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyxylv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllee_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyee_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllee_eR_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyee_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllll_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyee_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llllll_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyee_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvelv_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyll_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvelv_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyll_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvelv_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyvv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llveyx_eL_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyvv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llveyx_eL_pR.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyyy_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llveyx_eR_pL.root");        
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_yyyyyy_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvxyyx_eR_pL.root"); 
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvxyyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvxyev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvxyev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvxyev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvvyy_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvvyy_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvvxx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvvxx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvlyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvlyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvllv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvllv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvlev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvlev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvlev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveyx_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvelv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvelv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvvelv_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_vvveev_eL_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxyyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxyyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxylv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxylv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxyev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxyev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llxyev_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvlyx_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvlyx_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvllv_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvllv_eL_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvlev_eR_pR.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvlev_eR_pL.root");
	filename.push_back("/afs/desy.de/user/s/swathi/my_nafhh/MarlinReco/Analysis/submit_jobs/output/combined_output_files/root_files/rv02-00-01_sv02-00-01_mILD_l5_o1_v02_E500_llvlev_eL_pR.root");



	TCanvas* can= new TCanvas ("c","c",800,600);
	auto leg = new TLegend(0.7,0.65,0.9,0.95);
	double I,In;
	//leg->SetHeader("Cut Flow","C"); 
	std::vector<TFile*> in_file;
	std::vector <TH1F*> hvariable;
	hvariable.resize(filename.size());
	for(int i=0;i<filename.size();i++){
	       TFile* in_file_tmp=new TFile(filename[i].c_str());
	       in_file.push_back(in_file_tmp);
	}

	TH1F* h1 = new TH1F("Cut Flow","", 4, 0, 4);
	TH1F* h2 = new TH1F("Cut Flow","", 4, 0, 4);
	TH1F* h3 = new TH1F("Cut Flow","", 4, 0, 4);
	TH1F* h4 = new TH1F("Cut Flow","", 4, 0, 4);
	TH1F* h5 = new TH1F("Cut Flow","", 4, 0, 4);

	const char *binlabels[4]={"nocut","ntrk","ISR","Emiss"};
	for(int i=1;i<5;i++) {
	       h1->GetXaxis()->SetBinLabel(i,binlabels[i-1]);
	       h2->GetXaxis()->SetBinLabel(i,binlabels[i-1]);
	       h3->GetXaxis()->SetBinLabel(i,binlabels[i-1]);
	       h4->GetXaxis()->SetBinLabel(i,binlabels[i-1]);
	       h5->GetXaxis()->SetBinLabel(i,binlabels[i-1]);

	}



	THStack *hs1 = new THStack();
	THStack *hs2 = new THStack();
	THStack *hs3 = new THStack();
	THStack *hs4 = new THStack();
	THStack *hs5 = new THStack();

	for(int nfile=0;nfile<filename.size();nfile++){
	       TString hcut ="hcut"; 
	      
	       hvariable[nfile] =new TH1F("D0_sig","histoname",4,0,4);


	       if(nfile==44 || nfile==45){
		      hvariable[nfile] = (TH1F*)in_file[nfile]->Get(hcut);
		      h3->Add(hvariable[nfile]);
		    
		     
		     
	       }
	       if(nfile==44){
		      hvariable[nfile]->SetLineColor(6);
		      leg->AddEntry(h3," #tilde{#chi}^{+}_{1} #tilde{#chi}^{-}_{1}","f");     
	       }

	       if(nfile==46 || nfile==47){
		      hvariable[nfile] = (TH1F*)in_file[nfile]->Get(hcut);
		      h4->Add(hvariable[nfile]);
		    
		     
		     

	       }
	       if(nfile==46){

		    
		      leg->AddEntry(h4,"#tilde{#chi}^{0}_{1} #tilde{#chi}^{0}_{2}","f");
	       }





	       if(nfile==0 || nfile==1 || nfile==2 || nfile==3 || nfile==4 || nfile==5 || nfile==6 || nfile==7){
		      
		      hvariable[nfile] = (TH1F*)in_file[nfile]->Get(hcut);
		      h1->Add(hvariable[nfile]);
		     
		     

	       }


	       if(nfile==0){
		     
		      leg->AddEntry(h1,"ee#rightarrow 2f","f");
	       }


	       if(nfile==8 || nfile==9 || nfile==10 || nfile==11 || nfile==12 || nfile==13 || nfile==14 || nfile==15 || nfile==16 || nfile==17|| nfile==18 || nfile==19 || nfile==20 || nfile==21  || nfile==22|| nfile==23 || nfile==24  || nfile==25 || nfile==26 || nfile==27 || nfile==28|| nfile==29 || nfile==30  || nfile==31 || nfile==32 || nfile==33 || nfile==34 || nfile==35|| nfile==36  || nfile==37|| nfile==38 || nfile==39 || nfile==40 || nfile==41 || nfile==42  || nfile==43){
		      
		      hvariable[nfile] = (TH1F*)in_file[nfile]->Get(hcut);
		      h2->Add(hvariable[nfile]);
		     
		     
		     
		     

	       }
	       if(nfile==8){
		     
		      leg->AddEntry(h2,"ee#rightarrow 4f","f");
		     
	       }

	      
	       if(nfile==48 || nfile==49 || nfile==50 || nfile==51 || nfile==52 || nfile==53 || nfile==54 || nfile==55 || nfile==56 || nfile==57|| nfile==58 || nfile==59 || nfile==60 || nfile==61  || nfile==62|| nfile==63 || nfile==64  || nfile==65 || nfile==66 || nfile==67 || nfile==68|| nfile==69 || nfile==70  || nfile==71 || nfile==72 || nfile==73 || nfile==74 || nfile==75|| nfile==76  || nfile==77|| nfile==78 || nfile==79 || nfile==80 || nfile==81 || nfile==82  || nfile==83 || nfile==84  || nfile==85 || nfile==86 || nfile==87 || nfile==88 || nfile==89 || nfile==90 || nfile==91 || nfile==92 || nfile==93 || nfile==94 || nfile==95 || nfile==96 || nfile==97|| nfile==98 || nfile==99 || nfile==100 || nfile==101  || nfile==102|| nfile==103 || nfile==104  || nfile==105 || nfile==106 || nfile==107 || nfile==108|| nfile==109 || nfile==110  || nfile==111 || nfile==112 || nfile==113 || nfile==114 || nfile==115|| nfile==116  || nfile==117|| nfile==118 || nfile==119 || nfile==120 || nfile==121 || nfile==122  || nfile==123 || nfile==124 || nfile==125|| nfile==126  || nfile==127|| nfile==128 || nfile==129 || nfile==130 || nfile==131 || nfile==132  || nfile==133 || nfile==134 || nfile==135|| nfile==136  || nfile==137 || nfile==138 || nfile==139){

		      hvariable[nfile] = (TH1F*)in_file[nfile]->Get(hcut);
		      h5->Add(hvariable[nfile]);
		     


	       }

	       if(nfile==46){
		    
		      leg->AddEntry(h5,"ee#rightarrow 6f","f");
	       }


  	}


	h4->SetFillColor(45);
	h3->SetFillColor(42);
	h1->SetFillColor(40);
	h2->SetFillColor(46);
	h5->SetFillColor(30);

	hs1->Add(h3);
	hs1->Add(h4);
	hs1->Add(h1);
	hs1->Add(h2);
	hs1->Add(h5);

	THStack *s = new THStack();
	for(int i=0;i<filename.size();i++){
		s->Add(hvariable[i]);
	}


	hs1->Draw("HIST");
	//hs2->Draw("SAME");
	//hs1->Draw("SAME");
	//hs4->Draw("SAME");
	//hs3->Draw("SAME");
	leg->Draw();




}
