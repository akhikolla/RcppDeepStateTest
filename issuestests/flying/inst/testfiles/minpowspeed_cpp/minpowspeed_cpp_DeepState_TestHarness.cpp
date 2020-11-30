#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector minpowspeed_cpp(NumericVector bm, NumericVector ws, double ipf, double g, double airDensity, double bdc);

TEST(flying_deepstate_test,minpowspeed_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector bm  = RcppDeepState_NumericVector();
  qs::c_qsave(bm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/bm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bm values: "<< bm << std::endl;
  NumericVector ws  = RcppDeepState_NumericVector();
  qs::c_qsave(ws,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/ws.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ws values: "<< ws << std::endl;
  NumericVector ipf(1);
  ipf[0]  = RcppDeepState_double();
  qs::c_qsave(ipf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/ipf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ipf values: "<< ipf << std::endl;
  NumericVector g(1);
  g[0]  = RcppDeepState_double();
  qs::c_qsave(g,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/g.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector airDensity(1);
  airDensity[0]  = RcppDeepState_double();
  qs::c_qsave(airDensity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/airDensity.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "airDensity values: "<< airDensity << std::endl;
  NumericVector bdc(1);
  bdc[0]  = RcppDeepState_double();
  qs::c_qsave(bdc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/minpowspeed_cpp/inputs/bdc.qs",
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
