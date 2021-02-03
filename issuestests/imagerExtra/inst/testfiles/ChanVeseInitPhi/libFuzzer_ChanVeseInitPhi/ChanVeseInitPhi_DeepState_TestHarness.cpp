#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix ChanVeseInitPhi(int Width, int Height);

TEST(imagerExtra_deepstate_test,ChanVeseInitPhi_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector Width(1);
  Width[0]  = RcppDeepState_int();
  std::string Width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi/libFuzzer_ChanVeseInitPhi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Width.qs";
  qs::c_qsave(Width,Width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Width values: "<< Width << std::endl;
  IntegerVector Height(1);
  Height[0]  = RcppDeepState_int();
  std::string Height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVeseInitPhi/libFuzzer_ChanVeseInitPhi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Height.qs";
  qs::c_qsave(Height,Height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Height values: "<< Height << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ChanVeseInitPhi(Width[0],Height[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
