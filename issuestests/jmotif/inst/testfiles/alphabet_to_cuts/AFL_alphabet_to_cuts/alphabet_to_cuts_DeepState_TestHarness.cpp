#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector alphabet_to_cuts(int a_size);

TEST(jmotif_deepstate_test,alphabet_to_cuts_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector a_size(1);
  a_size[0]  = RcppDeepState_int();
  std::string a_size_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/alphabet_to_cuts/AFL_alphabet_to_cuts/afl_inputs/" + std::to_string(t) + "_a_size.qs";
  qs::c_qsave(a_size,a_size_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a_size values: "<< a_size << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    alphabet_to_cuts(a_size[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
