#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List predCoef(NumericVector X, int P, int H, IntegerVector t, IntegerVector N);

TEST(forecastSNSTS_deepstate_test,predCoef_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/predCoef/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  IntegerVector P(1);
  P[0]  = RcppDeepState_int();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/predCoef/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector H(1);
  H[0]  = RcppDeepState_int();
  qs::c_qsave(H,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/predCoef/inputs/H.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "H values: "<< H << std::endl;
  IntegerVector t  = RcppDeepState_IntegerVector();
  qs::c_qsave(t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/predCoef/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  IntegerVector N  = RcppDeepState_IntegerVector();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/predCoef/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    predCoef(X,P[0],H[0],t,N);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
