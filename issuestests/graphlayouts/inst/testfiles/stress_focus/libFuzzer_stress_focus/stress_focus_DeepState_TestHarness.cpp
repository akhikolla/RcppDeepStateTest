#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix stress_focus(NumericMatrix y, NumericMatrix W, NumericMatrix D, NumericMatrix Z, NumericVector tseq, int iter, double tol);

TEST(graphlayouts_deepstate_test,stress_focus_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  std::string W_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_W.qs";
  qs::c_qsave(W,W_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  NumericMatrix D  = RcppDeepState_NumericMatrix();
  std::string D_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_D.qs";
  qs::c_qsave(D,D_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D values: "<< D << std::endl;
  NumericMatrix Z  = RcppDeepState_NumericMatrix();
  std::string Z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Z.qs";
  qs::c_qsave(Z,Z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  NumericVector tseq  = RcppDeepState_NumericVector();
  std::string tseq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tseq.qs";
  qs::c_qsave(tseq,tseq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tseq values: "<< tseq << std::endl;
  IntegerVector iter(1);
  iter[0]  = RcppDeepState_int();
  std::string iter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iter.qs";
  qs::c_qsave(iter,iter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iter values: "<< iter << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/stress_focus/libFuzzer_stress_focus/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    stress_focus(y,W,D,Z,tseq,iter[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
