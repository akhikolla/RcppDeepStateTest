#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_arraytomat(Rcpp::NumericVector arr3d, int c, int A, int B, int C);

TEST(NHMM_deepstate_test,rcpp_arraytomat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector arr3d  = RcppDeepState_NumericVector();
  qs::c_qsave(arr3d,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/inputs/arr3d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "arr3d values: "<< arr3d << std::endl;
  IntegerVector c(1);
  c[0]  = RcppDeepState_int();
  qs::c_qsave(c,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/inputs/c.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  IntegerVector A(1);
  A[0]  = RcppDeepState_int();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  IntegerVector B(1);
  B[0]  = RcppDeepState_int();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector C(1);
  C[0]  = RcppDeepState_int();
  qs::c_qsave(C,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/inputs/C.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "C values: "<< C << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_arraytomat(arr3d,c[0],A[0],B[0],C[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
