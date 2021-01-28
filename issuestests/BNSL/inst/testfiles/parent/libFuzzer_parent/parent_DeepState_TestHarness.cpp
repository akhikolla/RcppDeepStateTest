#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame parent(NumericMatrix df0, int h, int tw, int proc);

TEST(BNSL_deepstate_test,parent_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix df0  = RcppDeepState_NumericMatrix();
  std::string df0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/libFuzzer_parent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_df0.qs";
  qs::c_qsave(df0,df0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df0 values: "<< df0 << std::endl;
  IntegerVector h(1);
  h[0]  = RcppDeepState_int();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/libFuzzer_parent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  IntegerVector tw(1);
  tw[0]  = RcppDeepState_int();
  std::string tw_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/libFuzzer_parent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tw.qs";
  qs::c_qsave(tw,tw_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tw values: "<< tw << std::endl;
  IntegerVector proc(1);
  proc[0]  = RcppDeepState_int();
  std::string proc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/libFuzzer_parent/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_proc.qs";
  qs::c_qsave(proc,proc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proc values: "<< proc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    parent(df0,h[0],tw[0],proc[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
