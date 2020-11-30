#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_curl1(NumericMatrix u, NumericMatrix v, NumericVector x, NumericVector y, NumericVector geographical);

TEST(oce_deepstate_test,do_curl1_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix u  = RcppDeepState_NumericMatrix();
  qs::c_qsave(u,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/inputs/u.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  NumericMatrix v  = RcppDeepState_NumericMatrix();
  qs::c_qsave(v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/inputs/v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector geographical  = RcppDeepState_NumericVector();
  qs::c_qsave(geographical,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_curl1/inputs/geographical.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "geographical values: "<< geographical << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_curl1(u,v,x,y,geographical);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
