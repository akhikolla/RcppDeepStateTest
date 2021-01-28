#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector cubestratified(NumericVector prob, NumericMatrix Xbal, IntegerVector integerStrata);

TEST(BalancedSampling_deepstate_test,cubestratified_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  std::string prob_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/cubestratified/libFuzzer_cubestratified/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prob.qs";
  qs::c_qsave(prob,prob_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  std::string Xbal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/cubestratified/libFuzzer_cubestratified/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xbal.qs";
  qs::c_qsave(Xbal,Xbal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xbal values: "<< Xbal << std::endl;
  IntegerVector integerStrata  = RcppDeepState_IntegerVector();
  std::string integerStrata_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/cubestratified/libFuzzer_cubestratified/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_integerStrata.qs";
  qs::c_qsave(integerStrata,integerStrata_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "integerStrata values: "<< integerStrata << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cubestratified(prob,Xbal,integerStrata);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
