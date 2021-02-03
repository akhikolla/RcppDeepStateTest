#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix func_coef(NumericMatrix z, int scale);

TEST(factorcpt_deepstate_test,func_coef_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_coef/libFuzzer_func_coef/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  IntegerVector scale(1);
  scale[0]  = RcppDeepState_int();
  std::string scale_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_coef/libFuzzer_func_coef/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_scale.qs";
  qs::c_qsave(scale,scale_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scale values: "<< scale << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    func_coef(z,scale[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
