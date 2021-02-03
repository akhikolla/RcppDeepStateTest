#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix stress_radii(NumericMatrix y, NumericMatrix W, NumericMatrix D, NumericVector r, NumericVector tseq);

TEST(graphlayouts_deepstate_test,stress_radii_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_radii/libFuzzer_stress_radii/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  std::string W_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_radii/libFuzzer_stress_radii/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_W.qs";
  qs::c_qsave(W,W_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  NumericMatrix D  = RcppDeepState_NumericMatrix();
  std::string D_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_radii/libFuzzer_stress_radii/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_D.qs";
  qs::c_qsave(D,D_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D values: "<< D << std::endl;
  NumericVector r  = RcppDeepState_NumericVector();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_radii/libFuzzer_stress_radii/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  NumericVector tseq  = RcppDeepState_NumericVector();
  std::string tseq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_radii/libFuzzer_stress_radii/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tseq.qs";
  qs::c_qsave(tseq,tseq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tseq values: "<< tseq << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    stress_radii(y,W,D,r,tseq);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
