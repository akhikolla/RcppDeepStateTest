#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix kr2p_ow_cpp(double SWCON, double SWCRIT, double SOIRW, double SORW, double KRWIRO, double KROCW, double NW, double NOW, int NP);

TEST(Rrelperm_deepstate_test,kr2p_ow_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  std::string SWCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_SWCON.qs";
  qs::c_qsave(SWCON,SWCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SWCRIT(1);
  SWCRIT[0]  = RcppDeepState_double();
  std::string SWCRIT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_SWCRIT.qs";
  qs::c_qsave(SWCRIT,SWCRIT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCRIT values: "<< SWCRIT << std::endl;
  NumericVector SOIRW(1);
  SOIRW[0]  = RcppDeepState_double();
  std::string SOIRW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_SOIRW.qs";
  qs::c_qsave(SOIRW,SOIRW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SOIRW values: "<< SOIRW << std::endl;
  NumericVector SORW(1);
  SORW[0]  = RcppDeepState_double();
  std::string SORW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_SORW.qs";
  qs::c_qsave(SORW,SORW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORW values: "<< SORW << std::endl;
  NumericVector KRWIRO(1);
  KRWIRO[0]  = RcppDeepState_double();
  std::string KRWIRO_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_KRWIRO.qs";
  qs::c_qsave(KRWIRO,KRWIRO_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KRWIRO values: "<< KRWIRO << std::endl;
  NumericVector KROCW(1);
  KROCW[0]  = RcppDeepState_double();
  std::string KROCW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_KROCW.qs";
  qs::c_qsave(KROCW,KROCW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROCW values: "<< KROCW << std::endl;
  NumericVector NW(1);
  NW[0]  = RcppDeepState_double();
  std::string NW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_NW.qs";
  qs::c_qsave(NW,NW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NW values: "<< NW << std::endl;
  NumericVector NOW(1);
  NOW[0]  = RcppDeepState_double();
  std::string NOW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_NOW.qs";
  qs::c_qsave(NOW,NOW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOW values: "<< NOW << std::endl;
  IntegerVector NP(1);
  NP[0]  = RcppDeepState_int();
  std::string NP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_ow_cpp/AFL_kr2p_ow_cpp/afl_inputs/" + std::to_string(t) + "_NP.qs";
  qs::c_qsave(NP,NP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NP values: "<< NP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kr2p_ow_cpp(SWCON[0],SWCRIT[0],SOIRW[0],SORW[0],KRWIRO[0],KROCW[0],NW[0],NOW[0],NP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
