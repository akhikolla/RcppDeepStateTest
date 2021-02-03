#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector cortMonteCarlo(const NumericMatrix z, const NumericMatrix min, const NumericMatrix max, const int N);

TEST(cort_deepstate_test,cortMonteCarlo_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/cortMonteCarlo/libFuzzer_cortMonteCarlo/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericMatrix min  = RcppDeepState_NumericMatrix();
  std::string min_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/cortMonteCarlo/libFuzzer_cortMonteCarlo/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_min.qs";
  qs::c_qsave(min,min_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min values: "<< min << std::endl;
  NumericMatrix max  = RcppDeepState_NumericMatrix();
  std::string max_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/cortMonteCarlo/libFuzzer_cortMonteCarlo/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max.qs";
  qs::c_qsave(max,max_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max values: "<< max << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/cortMonteCarlo/libFuzzer_cortMonteCarlo/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cortMonteCarlo(z,min,max,N[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
