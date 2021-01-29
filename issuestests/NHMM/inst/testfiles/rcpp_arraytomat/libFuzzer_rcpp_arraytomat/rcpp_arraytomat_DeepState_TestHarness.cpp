#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_arraytomat(Rcpp::NumericVector arr3d, int c, int A, int B, int C);

TEST(NHMM_deepstate_test,rcpp_arraytomat_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector arr3d  = RcppDeepState_NumericVector();
  std::string arr3d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/libFuzzer_rcpp_arraytomat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_arr3d.qs";
  qs::c_qsave(arr3d,arr3d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "arr3d values: "<< arr3d << std::endl;
  IntegerVector c(1);
  c[0]  = RcppDeepState_int();
  std::string c_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/libFuzzer_rcpp_arraytomat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_c.qs";
  qs::c_qsave(c,c_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  IntegerVector A(1);
  A[0]  = RcppDeepState_int();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/libFuzzer_rcpp_arraytomat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  IntegerVector B(1);
  B[0]  = RcppDeepState_int();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/libFuzzer_rcpp_arraytomat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector C(1);
  C[0]  = RcppDeepState_int();
  std::string C_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_arraytomat/libFuzzer_rcpp_arraytomat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_C.qs";
  qs::c_qsave(C,C_t,
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
