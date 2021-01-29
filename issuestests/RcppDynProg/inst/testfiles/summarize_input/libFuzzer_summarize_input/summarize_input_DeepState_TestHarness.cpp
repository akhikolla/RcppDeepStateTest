#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List summarize_input(NumericVector x, NumericVector y, NumericVector w, const int i, const int j, const int skip);

TEST(RcppDynProg_deepstate_test,summarize_input_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector i(1);
  i[0]  = RcppDeepState_int();
  std::string i_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_i.qs";
  qs::c_qsave(i,i_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i values: "<< i << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  std::string j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_j.qs";
  qs::c_qsave(j,j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  IntegerVector skip(1);
  skip[0]  = RcppDeepState_int();
  std::string skip_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/summarize_input/libFuzzer_summarize_input/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_skip.qs";
  qs::c_qsave(skip,skip_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "skip values: "<< skip << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    summarize_input(x,y,w,i[0],j[0],skip[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
