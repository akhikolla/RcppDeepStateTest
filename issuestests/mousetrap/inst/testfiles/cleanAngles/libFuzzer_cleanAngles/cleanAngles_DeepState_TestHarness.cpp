#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix cleanAngles(NumericMatrix as);

TEST(mousetrap_deepstate_test,cleanAngles_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix as  = RcppDeepState_NumericMatrix();
  std::string as_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/cleanAngles/libFuzzer_cleanAngles/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_as.qs";
  qs::c_qsave(as,as_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "as values: "<< as << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cleanAngles(as);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
