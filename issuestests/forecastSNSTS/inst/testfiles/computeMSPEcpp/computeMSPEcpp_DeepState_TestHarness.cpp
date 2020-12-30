#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector computeMSPEcpp(NumericVector X, NumericVector coef, int h, IntegerVector t, int type, double trimLo, double trimUp);

TEST(forecastSNSTS_deepstate_test,computeMSPEcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector coef  = RcppDeepState_NumericVector();
  qs::c_qsave(coef,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/coef.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coef values: "<< coef << std::endl;
  IntegerVector h(1);
  h[0]  = RcppDeepState_int();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  IntegerVector t  = RcppDeepState_IntegerVector();
  qs::c_qsave(t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  qs::c_qsave(type,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector trimLo(1);
  trimLo[0]  = RcppDeepState_double();
  qs::c_qsave(trimLo,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/trimLo.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trimLo values: "<< trimLo << std::endl;
  NumericVector trimUp(1);
  trimUp[0]  = RcppDeepState_double();
  qs::c_qsave(trimUp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/inputs/trimUp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trimUp values: "<< trimUp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeMSPEcpp(X,coef,h[0],t,type[0],trimLo[0],trimUp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
