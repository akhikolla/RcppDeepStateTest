#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix spatialize4d(NumericVector x, NumericVector y, NumericVector z1, NumericVector z2, int npts);

TEST(mousetrap_deepstate_test,spatialize4d_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z1  = RcppDeepState_NumericVector();
  qs::c_qsave(z1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/inputs/z1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z1 values: "<< z1 << std::endl;
  NumericVector z2  = RcppDeepState_NumericVector();
  qs::c_qsave(z2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/inputs/z2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z2 values: "<< z2 << std::endl;
  IntegerVector npts(1);
  npts[0]  = RcppDeepState_int();
  qs::c_qsave(npts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/inputs/npts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "npts values: "<< npts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    spatialize4d(x,y,z1,z2,npts[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
