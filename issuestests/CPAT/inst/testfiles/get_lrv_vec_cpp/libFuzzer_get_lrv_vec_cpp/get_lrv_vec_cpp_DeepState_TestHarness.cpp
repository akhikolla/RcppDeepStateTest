#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_lrv_vec_cpp(NumericMatrix Y, NumericVector kern, int max_l);

TEST(CPAT_deepstate_test,get_lrv_vec_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/libFuzzer_get_lrv_vec_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector kern  = RcppDeepState_NumericVector();
  std::string kern_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/libFuzzer_get_lrv_vec_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_kern.qs";
  qs::c_qsave(kern,kern_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kern values: "<< kern << std::endl;
  IntegerVector max_l(1);
  max_l[0]  = RcppDeepState_int();
  std::string max_l_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/libFuzzer_get_lrv_vec_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_l.qs";
  qs::c_qsave(max_l,max_l_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_l values: "<< max_l << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_lrv_vec_cpp(Y,kern,max_l[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
