#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List StdVar_C_NA(NumericMatrix MyMat);

TEST(BoostMLR_deepstate_test,StdVar_C_NA_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix MyMat  = RcppDeepState_NumericMatrix();
  std::string MyMat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/StdVar_C_NA/libFuzzer_StdVar_C_NA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_MyMat.qs";
  qs::c_qsave(MyMat,MyMat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "MyMat values: "<< MyMat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    StdVar_C_NA(MyMat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
