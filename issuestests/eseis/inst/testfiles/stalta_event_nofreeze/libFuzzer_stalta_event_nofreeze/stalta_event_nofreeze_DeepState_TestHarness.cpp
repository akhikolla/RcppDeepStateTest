#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector stalta_event_nofreeze(int event_length, NumericVector ratio, double on, double off);

TEST(eseis_deepstate_test,stalta_event_nofreeze_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector event_length(1);
  event_length[0]  = RcppDeepState_int();
  std::string event_length_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/libFuzzer_stalta_event_nofreeze/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_event_length.qs";
  qs::c_qsave(event_length,event_length_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "event_length values: "<< event_length << std::endl;
  NumericVector ratio  = RcppDeepState_NumericVector();
  std::string ratio_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/libFuzzer_stalta_event_nofreeze/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ratio.qs";
  qs::c_qsave(ratio,ratio_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ratio values: "<< ratio << std::endl;
  NumericVector on(1);
  on[0]  = RcppDeepState_double();
  std::string on_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/libFuzzer_stalta_event_nofreeze/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_on.qs";
  qs::c_qsave(on,on_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "on values: "<< on << std::endl;
  NumericVector off(1);
  off[0]  = RcppDeepState_double();
  std::string off_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/libFuzzer_stalta_event_nofreeze/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_off.qs";
  qs::c_qsave(off,off_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "off values: "<< off << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    stalta_event_nofreeze(event_length[0],ratio,on[0],off[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
