#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

std::map<int, CharacterVector> sax_by_chunking(NumericVector ts, int paa_size, int a_size, double n_threshold);

TEST(jmotif_deepstate_test,sax_by_chunking_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/sax_by_chunking/AFL_sax_by_chunking/afl_inputs/" + std::to_string(t) + "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector paa_size(1);
  paa_size[0]  = RcppDeepState_int();
  std::string paa_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/sax_by_chunking/AFL_sax_by_chunking/afl_inputs/" + std::to_string(t) + "_paa_size.qs";
  qs::c_qsave(paa_size,paa_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "paa_size values: "<< paa_size << std::endl;
  IntegerVector a_size(1);
  a_size[0]  = RcppDeepState_int();
  std::string a_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/sax_by_chunking/AFL_sax_by_chunking/afl_inputs/" + std::to_string(t) + "_a_size.qs";
  qs::c_qsave(a_size,a_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_size values: "<< a_size << std::endl;
  NumericVector n_threshold(1);
  n_threshold[0]  = RcppDeepState_double();
  std::string n_threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/sax_by_chunking/AFL_sax_by_chunking/afl_inputs/" + std::to_string(t) + "_n_threshold.qs";
  qs::c_qsave(n_threshold,n_threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_threshold values: "<< n_threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sax_by_chunking(ts,paa_size[0],a_size[0],n_threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
