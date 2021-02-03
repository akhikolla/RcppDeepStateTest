#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::ComplexMatrix IDCT2D_toDFT(Rcpp::NumericMatrix mat);

TEST(imagerExtra_deepstate_test,IDCT2D_toDFT_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  std::string mat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/IDCT2D_toDFT/libFuzzer_IDCT2D_toDFT/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mat.qs";
  qs::c_qsave(mat,mat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    IDCT2D_toDFT(mat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
