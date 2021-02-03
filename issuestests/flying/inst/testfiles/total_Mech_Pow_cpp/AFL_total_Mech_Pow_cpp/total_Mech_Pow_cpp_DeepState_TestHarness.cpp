#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector total_Mech_Pow_cpp(NumericVector bm, NumericVector ws, NumericVector wa, NumericVector vt, double g, double airDensity, double ipf, double bdc, double ppc);

TEST(flying_deepstate_test,total_Mech_Pow_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector bm  = RcppDeepState_NumericVector();
  std::string bm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_bm.qs";
  qs::c_qsave(bm,bm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bm values: "<< bm << std::endl;
  NumericVector ws  = RcppDeepState_NumericVector();
  std::string ws_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_ws.qs";
  qs::c_qsave(ws,ws_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ws values: "<< ws << std::endl;
  NumericVector wa  = RcppDeepState_NumericVector();
  std::string wa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_wa.qs";
  qs::c_qsave(wa,wa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wa values: "<< wa << std::endl;
  NumericVector vt  = RcppDeepState_NumericVector();
  std::string vt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_vt.qs";
  qs::c_qsave(vt,vt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vt values: "<< vt << std::endl;
  NumericVector g(1);
  g[0]  = RcppDeepState_double();
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_g.qs";
  qs::c_qsave(g,g_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector airDensity(1);
  airDensity[0]  = RcppDeepState_double();
  std::string airDensity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_airDensity.qs";
  qs::c_qsave(airDensity,airDensity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "airDensity values: "<< airDensity << std::endl;
  NumericVector ipf(1);
  ipf[0]  = RcppDeepState_double();
  std::string ipf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_ipf.qs";
  qs::c_qsave(ipf,ipf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ipf values: "<< ipf << std::endl;
  NumericVector bdc(1);
  bdc[0]  = RcppDeepState_double();
  std::string bdc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_bdc.qs";
  qs::c_qsave(bdc,bdc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bdc values: "<< bdc << std::endl;
  NumericVector ppc(1);
  ppc[0]  = RcppDeepState_double();
  std::string ppc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/AFL_total_Mech_Pow_cpp/afl_inputs/" + std::to_string(t) + "_ppc.qs";
  qs::c_qsave(ppc,ppc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppc values: "<< ppc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    total_Mech_Pow_cpp(bm,ws,wa,vt,g[0],airDensity[0],ipf[0],bdc[0],ppc[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
