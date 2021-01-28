#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix twostep_grm_cpp(NumericMatrix genotype, NumericVector freq, NumericMatrix est0);

TEST(rres_deepstate_test,twostep_grm_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix genotype  = RcppDeepState_NumericMatrix();
  std::string genotype_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/libFuzzer_twostep_grm_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_genotype.qs";
  qs::c_qsave(genotype,genotype_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "genotype values: "<< genotype << std::endl;
  NumericVector freq  = RcppDeepState_NumericVector();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/libFuzzer_twostep_grm_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  NumericMatrix est0  = RcppDeepState_NumericMatrix();
  std::string est0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/libFuzzer_twostep_grm_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_est0.qs";
  qs::c_qsave(est0,est0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "est0 values: "<< est0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    twostep_grm_cpp(genotype,freq,est0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
