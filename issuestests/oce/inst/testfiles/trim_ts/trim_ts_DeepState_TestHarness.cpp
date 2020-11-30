#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List trim_ts(NumericVector x, NumericVector xlim, NumericVector extra);

TEST(oce_deepstate_test,trim_ts_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector xlim  = RcppDeepState_NumericVector();
  qs::c_qsave(xlim,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/inputs/xlim.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xlim values: "<< xlim << std::endl;
  NumericVector extra  = RcppDeepState_NumericVector();
  qs::c_qsave(extra,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/trim_ts/inputs/extra.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "extra values: "<< extra << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    trim_ts(x,xlim,extra);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
