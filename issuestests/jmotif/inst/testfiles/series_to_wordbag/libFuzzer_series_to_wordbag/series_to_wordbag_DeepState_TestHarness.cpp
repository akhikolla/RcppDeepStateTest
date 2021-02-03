#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::DataFrame series_to_wordbag(NumericVector ts, int w_size, int paa_size, int a_size, CharacterVector nr_strategy, double n_threshold);

TEST(jmotif_deepstate_test,series_to_wordbag_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector w_size(1);
  w_size[0]  = RcppDeepState_int();
  std::string w_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w_size.qs";
  qs::c_qsave(w_size,w_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w_size values: "<< w_size << std::endl;
  IntegerVector paa_size(1);
  paa_size[0]  = RcppDeepState_int();
  std::string paa_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_paa_size.qs";
  qs::c_qsave(paa_size,paa_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "paa_size values: "<< paa_size << std::endl;
  IntegerVector a_size(1);
  a_size[0]  = RcppDeepState_int();
  std::string a_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a_size.qs";
  qs::c_qsave(a_size,a_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_size values: "<< a_size << std::endl;
  CharacterVector nr_strategy  = RcppDeepState_CharacterVector();
  std::string nr_strategy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nr_strategy.qs";
  qs::c_qsave(nr_strategy,nr_strategy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr_strategy values: "<< nr_strategy << std::endl;
  NumericVector n_threshold(1);
  n_threshold[0]  = RcppDeepState_double();
  std::string n_threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/series_to_wordbag/libFuzzer_series_to_wordbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_threshold.qs";
  qs::c_qsave(n_threshold,n_threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_threshold values: "<< n_threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    series_to_wordbag(ts,w_size[0],paa_size[0],a_size[0],nr_strategy,n_threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
