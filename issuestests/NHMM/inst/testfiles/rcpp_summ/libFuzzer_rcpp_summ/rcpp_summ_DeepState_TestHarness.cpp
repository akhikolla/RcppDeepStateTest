#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_summ(Rcpp::NumericMatrix A);

TEST(NHMM_deepstate_test,rcpp_summ_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_summ/libFuzzer_rcpp_summ/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_summ(A);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
