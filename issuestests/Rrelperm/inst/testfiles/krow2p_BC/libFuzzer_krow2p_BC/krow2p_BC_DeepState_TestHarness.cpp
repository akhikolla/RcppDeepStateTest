#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double krow2p_BC(double SW, double SWCON, double SORW, double KROCW, double NOW);

TEST(Rrelperm_deepstate_test,krow2p_BC_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector SW(1);
  SW[0]  = RcppDeepState_double();
  std::string SW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SW.qs";
  qs::c_qsave(SW,SW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SW values: "<< SW << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  std::string SW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SW.qs";
  std::string SWCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SWCON.qs";
  qs::c_qsave(SWCON,SWCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SORW(1);
  SORW[0]  = RcppDeepState_double();
  std::string SORW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SORW.qs";
  qs::c_qsave(SORW,SORW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORW values: "<< SORW << std::endl;
  NumericVector KROCW(1);
  KROCW[0]  = RcppDeepState_double();
  std::string KROCW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_KROCW.qs";
  qs::c_qsave(KROCW,KROCW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROCW values: "<< KROCW << std::endl;
  NumericVector NOW(1);
  NOW[0]  = RcppDeepState_double();
  std::string NOW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/libFuzzer_krow2p_BC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NOW.qs";
  qs::c_qsave(NOW,NOW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOW values: "<< NOW << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    krow2p_BC(SW[0],SWCON[0],SORW[0],KROCW[0],NOW[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
