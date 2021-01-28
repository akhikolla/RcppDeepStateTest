#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List select_equal(IntegerVector x, int val1, int val2);

TEST(simPop_deepstate_test,select_equal_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/libFuzzer_select_equal/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector val1(1);
  val1[0]  = RcppDeepState_int();
  std::string val1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/libFuzzer_select_equal/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_val1.qs";
  qs::c_qsave(val1,val1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "val1 values: "<< val1 << std::endl;
  IntegerVector val2(1);
  val2[0]  = RcppDeepState_int();
  std::string val2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/libFuzzer_select_equal/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_val2.qs";
  qs::c_qsave(val2,val2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "val2 values: "<< val2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    select_equal(x,val1[0],val2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
