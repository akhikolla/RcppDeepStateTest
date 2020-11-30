#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_rnorm(int a, double b, double c);

TEST(NHMM_deepstate_test,rcpp_rnorm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector a(1);
  a[0]  = RcppDeepState_int();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rnorm/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b(1);
  b[0]  = RcppDeepState_double();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rnorm/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector c(1);
  c[0]  = RcppDeepState_double();
  qs::c_qsave(c,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rnorm/inputs/c.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_rnorm(a[0],b[0],c[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
