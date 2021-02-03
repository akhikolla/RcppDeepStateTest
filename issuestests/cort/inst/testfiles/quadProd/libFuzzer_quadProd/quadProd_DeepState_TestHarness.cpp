#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double quadProd(const NumericMatrix a, const NumericMatrix b, const NumericVector kern, const NumericMatrix other_a, const NumericMatrix other_b, const NumericVector other_kern);

TEST(cort_deepstate_test,quadProd_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix a  = RcppDeepState_NumericMatrix();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericMatrix b  = RcppDeepState_NumericMatrix();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector kern  = RcppDeepState_NumericVector();
  std::string kern_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_kern.qs";
  qs::c_qsave(kern,kern_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kern values: "<< kern << std::endl;
  NumericMatrix other_a  = RcppDeepState_NumericMatrix();
  std::string other_a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_a.qs";
  qs::c_qsave(other_a,other_a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_a values: "<< other_a << std::endl;
  NumericMatrix other_b  = RcppDeepState_NumericMatrix();
  std::string other_b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_b.qs";
  qs::c_qsave(other_b,other_b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_b values: "<< other_b << std::endl;
  NumericVector other_kern  = RcppDeepState_NumericVector();
  std::string other_kern_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/libFuzzer_quadProd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_kern.qs";
  qs::c_qsave(other_kern,other_kern_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_kern values: "<< other_kern << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    quadProd(a,b,kern,other_a,other_b,other_kern);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
