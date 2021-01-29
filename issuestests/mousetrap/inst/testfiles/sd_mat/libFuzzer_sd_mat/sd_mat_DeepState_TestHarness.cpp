#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double sd_mat(NumericMatrix mat);

TEST(mousetrap_deepstate_test,sd_mat_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  std::string mat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/sd_mat/libFuzzer_sd_mat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mat.qs";
  qs::c_qsave(mat,mat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sd_mat(mat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
