#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double lossFunc(const NumericVector bp, const NumericMatrix bin_repr, const NumericMatrix z);

TEST(cort_deepstate_test,lossFunc_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector bp  = RcppDeepState_NumericVector();
  std::string bp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/libFuzzer_lossFunc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_bp.qs";
  qs::c_qsave(bp,bp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bp values: "<< bp << std::endl;
  NumericMatrix bin_repr  = RcppDeepState_NumericMatrix();
  std::string bin_repr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/libFuzzer_lossFunc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_bin_repr.qs";
  qs::c_qsave(bin_repr,bin_repr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bin_repr values: "<< bin_repr << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/libFuzzer_lossFunc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lossFunc(bp,bin_repr,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
