#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List credsetmat(NumericMatrix pp, NumericVector iCV, double threshold);

TEST(corrcoverage_deepstate_test,credsetmat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix pp  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/inputs/pp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pp values: "<< pp << std::endl;
  NumericVector iCV  = RcppDeepState_NumericVector();
  qs::c_qsave(iCV,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/inputs/iCV.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iCV values: "<< iCV << std::endl;
  NumericVector threshold(1);
  threshold[0]  = RcppDeepState_double();
  qs::c_qsave(threshold,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/corrcoverage/inst/testfiles/credsetmat/inputs/threshold.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "threshold values: "<< threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    credsetmat(pp,iCV,threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
