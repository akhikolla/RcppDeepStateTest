#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix getVelocities3d(NumericMatrix xs, NumericMatrix ys, NumericMatrix zs);

TEST(mousetrap_deepstate_test,getVelocities3d_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix xs  = RcppDeepState_NumericMatrix();
  std::string xs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getVelocities3d/libFuzzer_getVelocities3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xs.qs";
  qs::c_qsave(xs,xs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  NumericMatrix ys  = RcppDeepState_NumericMatrix();
  std::string ys_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getVelocities3d/libFuzzer_getVelocities3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ys.qs";
  qs::c_qsave(ys,ys_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ys values: "<< ys << std::endl;
  NumericMatrix zs  = RcppDeepState_NumericMatrix();
  std::string zs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getVelocities3d/libFuzzer_getVelocities3d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_zs.qs";
  qs::c_qsave(zs,zs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zs values: "<< zs << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getVelocities3d(xs,ys,zs);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
