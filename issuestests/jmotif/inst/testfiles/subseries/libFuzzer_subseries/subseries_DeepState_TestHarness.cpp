#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector subseries(NumericVector ts, int start, int end);

TEST(jmotif_deepstate_test,subseries_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/subseries/libFuzzer_subseries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/subseries/libFuzzer_subseries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  IntegerVector end(1);
  end[0]  = RcppDeepState_int();
  std::string end_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/subseries/libFuzzer_subseries/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_end.qs";
  qs::c_qsave(end,end_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "end values: "<< end << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    subseries(ts,start[0],end[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
