#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector stalta_event_freeze(int event_length, NumericVector data_sta, NumericVector data_lta, double on, double off);

TEST(eseis_deepstate_test,stalta_event_freeze_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector event_length(1);
  event_length[0]  = RcppDeepState_int();
  qs::c_qsave(event_length,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_freeze/inputs/event_length.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "event_length values: "<< event_length << std::endl;
  NumericVector data_sta  = RcppDeepState_NumericVector();
  qs::c_qsave(data_sta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_freeze/inputs/data_sta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data_sta values: "<< data_sta << std::endl;
  NumericVector data_lta  = RcppDeepState_NumericVector();
  qs::c_qsave(data_lta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_freeze/inputs/data_lta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data_lta values: "<< data_lta << std::endl;
  NumericVector on(1);
  on[0]  = RcppDeepState_double();
  qs::c_qsave(on,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_freeze/inputs/on.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "on values: "<< on << std::endl;
  NumericVector off(1);
  off[0]  = RcppDeepState_double();
  qs::c_qsave(off,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_freeze/inputs/off.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "off values: "<< off << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    stalta_event_freeze(event_length[0],data_sta,data_lta,on[0],off[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
