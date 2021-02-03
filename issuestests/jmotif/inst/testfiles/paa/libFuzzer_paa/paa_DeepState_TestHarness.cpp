#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector paa(NumericVector ts, int paa_num);

TEST(jmotif_deepstate_test,paa_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/paa/libFuzzer_paa/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector paa_num(1);
  paa_num[0]  = RcppDeepState_int();
  std::string paa_num_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/paa/libFuzzer_paa/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_paa_num.qs";
  qs::c_qsave(paa_num,paa_num_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "paa_num values: "<< paa_num << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    paa(ts,paa_num[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
