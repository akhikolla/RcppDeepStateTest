#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double krgl2p_BC(double SG, double SWCON, double SORG, double SGCON, double KROGCG, double NOG);

TEST(Rrelperm_deepstate_test,krgl2p_BC_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector SG(1);
  SG[0]  = RcppDeepState_double();
  std::string SG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SG.qs";
  qs::c_qsave(SG,SG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SG values: "<< SG << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  std::string SWCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SWCON.qs";
  qs::c_qsave(SWCON,SWCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SORG(1);
  SORG[0]  = RcppDeepState_double();
  std::string SORG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SORG.qs";
  qs::c_qsave(SORG,SORG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORG values: "<< SORG << std::endl;
  NumericVector SGCON(1);
  SGCON[0]  = RcppDeepState_double();
  std::string SG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SG.qs";
  std::string SGCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SGCON.qs";
  qs::c_qsave(SGCON,SGCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SGCON values: "<< SGCON << std::endl;
  NumericVector KROGCG(1);
  KROGCG[0]  = RcppDeepState_double();
  std::string KROGCG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_KROGCG.qs";
  qs::c_qsave(KROGCG,KROGCG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROGCG values: "<< KROGCG << std::endl;
  NumericVector NOG(1);
  NOG[0]  = RcppDeepState_double();
  std::string NOG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krgl2p_BC/libFuzzer_krgl2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NOG.qs";
  qs::c_qsave(NOG,NOG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOG values: "<< NOG << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    krgl2p_BC(SG[0],SWCON[0],SORG[0],SGCON[0],KROGCG[0],NOG[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
