#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double calculate_test_error_(IntegerVector vardep, IntegerVector predicted_class_int);

TEST(fastAdaboost_deepstate_test,calculate_test_error__test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector vardep  = RcppDeepState_IntegerVector();
  std::string vardep_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fastAdaboost/inst/testfiles/calculate_test_error_/libFuzzer_calculate_test_error_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vardep.qs";
  qs::c_qsave(vardep,vardep_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vardep values: "<< vardep << std::endl;
  IntegerVector predicted_class_int  = RcppDeepState_IntegerVector();
  std::string predicted_class_int_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fastAdaboost/inst/testfiles/calculate_test_error_/libFuzzer_calculate_test_error_/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_predicted_class_int.qs";
  qs::c_qsave(predicted_class_int,predicted_class_int_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "predicted_class_int values: "<< predicted_class_int << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    calculate_test_error_(vardep,predicted_class_int);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
