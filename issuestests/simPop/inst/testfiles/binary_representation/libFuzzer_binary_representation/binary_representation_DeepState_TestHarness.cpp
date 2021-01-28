#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix binary_representation(IntegerVector levels, IntegerVector values);

TEST(simPop_deepstate_test,binary_representation_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector levels  = RcppDeepState_IntegerVector();
  std::string levels_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/binary_representation/libFuzzer_binary_representation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_levels.qs";
  qs::c_qsave(levels,levels_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "levels values: "<< levels << std::endl;
  IntegerVector values  = RcppDeepState_IntegerVector();
  std::string values_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/binary_representation/libFuzzer_binary_representation/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_values.qs";
  qs::c_qsave(values,values_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "values values: "<< values << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binary_representation(levels,values);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
