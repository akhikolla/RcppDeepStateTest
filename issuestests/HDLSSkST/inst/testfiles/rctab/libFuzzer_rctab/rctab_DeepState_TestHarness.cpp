#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

/* ------------------------Generating random RxC contigency tables-----------------------------*/    Rcpp::NumericMatrix rctab(Rcpp::NumericMatrix M);

TEST(HDLSSkST_deepstate_test,rctab_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  std::string M_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/HDLSSkST/inst/testfiles/rctab/libFuzzer_rctab/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_M.qs";
  qs::c_qsave(M,M_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rctab(M);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
