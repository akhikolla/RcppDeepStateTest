#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::DataFrame find_discords_hotsax(NumericVector ts, int w_size, int paa_size, int a_size, double n_threshold, int discords_num);

TEST(jmotif_deepstate_test,find_discords_hotsax_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector w_size(1);
  w_size[0]  = RcppDeepState_int();
  std::string w_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w_size.qs";
  qs::c_qsave(w_size,w_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w_size values: "<< w_size << std::endl;
  IntegerVector paa_size(1);
  paa_size[0]  = RcppDeepState_int();
  std::string paa_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_paa_size.qs";
  qs::c_qsave(paa_size,paa_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "paa_size values: "<< paa_size << std::endl;
  IntegerVector a_size(1);
  a_size[0]  = RcppDeepState_int();
  std::string a_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a_size.qs";
  qs::c_qsave(a_size,a_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_size values: "<< a_size << std::endl;
  NumericVector n_threshold(1);
  n_threshold[0]  = RcppDeepState_double();
  std::string n_threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_threshold.qs";
  qs::c_qsave(n_threshold,n_threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_threshold values: "<< n_threshold << std::endl;
  IntegerVector discords_num(1);
  discords_num[0]  = RcppDeepState_int();
  std::string discords_num_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/find_discords_hotsax/libFuzzer_find_discords_hotsax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_discords_num.qs";
  qs::c_qsave(discords_num,discords_num_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "discords_num values: "<< discords_num << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    find_discords_hotsax(ts,w_size[0],paa_size[0],a_size[0],n_threshold[0],discords_num[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
