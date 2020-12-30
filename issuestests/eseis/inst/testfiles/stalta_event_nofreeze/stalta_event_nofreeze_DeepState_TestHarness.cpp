#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector stalta_event_nofreeze(int event_length, NumericVector ratio, double on, double off);

TEST(eseis_deepstate_test,stalta_event_nofreeze_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector event_length(1);
  event_length[0]  = RcppDeepState_int();
  qs::c_qsave(event_length,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/inputs/event_length.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "event_length values: "<< event_length << std::endl;
  NumericVector ratio  = RcppDeepState_NumericVector();
  qs::c_qsave(ratio,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/inputs/ratio.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ratio values: "<< ratio << std::endl;
  NumericVector on(1);
  on[0]  = RcppDeepState_double();
  qs::c_qsave(on,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/inputs/on.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "on values: "<< on << std::endl;
  NumericVector off(1);
  off[0]  = RcppDeepState_double();
  qs::c_qsave(off,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/eseis/inst/testfiles/stalta_event_nofreeze/inputs/off.qs",
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
