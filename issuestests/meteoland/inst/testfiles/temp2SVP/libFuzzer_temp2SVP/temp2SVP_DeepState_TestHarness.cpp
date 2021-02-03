#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector temp2SVP(NumericVector TD);

TEST(meteoland_deepstate_test,temp2SVP_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector TD  = RcppDeepState_NumericVector();
  std::string TD_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/temp2SVP/libFuzzer_temp2SVP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_TD.qs";
  qs::c_qsave(TD,TD_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TD values: "<< TD << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    temp2SVP(TD);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
