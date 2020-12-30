#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector total_Mech_Pow_cpp(NumericVector bm, NumericVector ws, NumericVector wa, NumericVector vt, double g, double airDensity, double ipf, double bdc, double ppc);

TEST(flying_deepstate_test,total_Mech_Pow_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector bm  = RcppDeepState_NumericVector();
  qs::c_qsave(bm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/bm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bm values: "<< bm << std::endl;
  NumericVector ws  = RcppDeepState_NumericVector();
  qs::c_qsave(ws,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/ws.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ws values: "<< ws << std::endl;
  NumericVector wa  = RcppDeepState_NumericVector();
  qs::c_qsave(wa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/wa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wa values: "<< wa << std::endl;
  NumericVector vt  = RcppDeepState_NumericVector();
  qs::c_qsave(vt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/vt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vt values: "<< vt << std::endl;
  NumericVector g(1);
  g[0]  = RcppDeepState_double();
  qs::c_qsave(g,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/g.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector airDensity(1);
  airDensity[0]  = RcppDeepState_double();
  qs::c_qsave(airDensity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/airDensity.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "airDensity values: "<< airDensity << std::endl;
  NumericVector ipf(1);
  ipf[0]  = RcppDeepState_double();
  qs::c_qsave(ipf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/ipf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ipf values: "<< ipf << std::endl;
  NumericVector bdc(1);
  bdc[0]  = RcppDeepState_double();
  qs::c_qsave(bdc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/bdc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bdc values: "<< bdc << std::endl;
  NumericVector ppc(1);
  ppc[0]  = RcppDeepState_double();
  qs::c_qsave(ppc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/flying/inst/testfiles/total_Mech_Pow_cpp/inputs/ppc.qs",
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
