#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_oce_convolve(NumericVector x, NumericVector f, NumericVector end);

TEST(oce_deepstate_test,do_oce_convolve_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/inputs/f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  NumericVector end  = RcppDeepState_NumericVector();
  qs::c_qsave(end,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_oce_convolve/inputs/end.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "end values: "<< end << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_oce_convolve(x,f,end);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
