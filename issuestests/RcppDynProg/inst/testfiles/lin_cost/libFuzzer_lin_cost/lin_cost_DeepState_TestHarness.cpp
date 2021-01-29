#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double lin_cost(NumericVector x, NumericVector y, NumericVector w, const int min_seg, const int i, const int j);

TEST(RcppDynProg_deepstate_test,lin_cost_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector min_seg(1);
  min_seg[0]  = RcppDeepState_int();
  std::string min_seg_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_min_seg.qs";
  qs::c_qsave(min_seg,min_seg_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_seg values: "<< min_seg << std::endl;
  IntegerVector i(1);
  i[0]  = RcppDeepState_int();
  std::string i_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_i.qs";
  qs::c_qsave(i,i_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i values: "<< i << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  std::string j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/lin_cost/libFuzzer_lin_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_j.qs";
  qs::c_qsave(j,j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lin_cost(x,y,w,min_seg[0],i[0],j[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
