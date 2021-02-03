#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector minpowspeed_cpp(NumericVector bm, NumericVector ws, double ipf, double g, double airDensity, double bdc);

TEST(flying_deepstate_test,minpowspeed_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector bm  = RcppDeepState_NumericVector();
  std::string bm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_bm.qs";
  qs::c_qsave(bm,bm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bm values: "<< bm << std::endl;
  NumericVector ws  = RcppDeepState_NumericVector();
  std::string ws_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_ws.qs";
  qs::c_qsave(ws,ws_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ws values: "<< ws << std::endl;
  NumericVector ipf(1);
  ipf[0]  = RcppDeepState_double();
  std::string ipf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_ipf.qs";
  qs::c_qsave(ipf,ipf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ipf values: "<< ipf << std::endl;
  NumericVector g(1);
  g[0]  = RcppDeepState_double();
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(g,g_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector airDensity(1);
  airDensity[0]  = RcppDeepState_double();
  std::string airDensity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_airDensity.qs";
  qs::c_qsave(airDensity,airDensity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "airDensity values: "<< airDensity << std::endl;
  NumericVector bdc(1);
  bdc[0]  = RcppDeepState_double();
  std::string bdc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/AFL_minpowspeed_cpp/afl_inputs/" + std::to_string(t) + "_bdc.qs";
  qs::c_qsave(bdc,bdc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bdc values: "<< bdc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    minpowspeed_cpp(bm,ws,ipf[0],g[0],airDensity[0],bdc[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
