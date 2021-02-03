#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix func_input_on(NumericMatrix coef);

TEST(factorcpt_deepstate_test,func_input_on_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix coef  = RcppDeepState_NumericMatrix();
  std::string coef_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_input_on/libFuzzer_func_input_on/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_coef.qs";
  qs::c_qsave(coef,coef_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coef values: "<< coef << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    func_input_on(coef);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
