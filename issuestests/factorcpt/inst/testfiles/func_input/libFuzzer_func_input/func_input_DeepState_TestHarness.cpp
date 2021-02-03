#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix func_input(NumericMatrix coef, NumericMatrix sgn);

TEST(factorcpt_deepstate_test,func_input_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix coef  = RcppDeepState_NumericMatrix();
  std::string coef_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_input/libFuzzer_func_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_coef.qs";
  qs::c_qsave(coef,coef_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coef values: "<< coef << std::endl;
  NumericMatrix sgn  = RcppDeepState_NumericMatrix();
  std::string sgn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_input/libFuzzer_func_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sgn.qs";
  qs::c_qsave(sgn,sgn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sgn values: "<< sgn << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    func_input(coef,sgn);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
