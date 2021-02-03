#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int Minimum(IntegerVector data);

TEST(autothresholdr_deepstate_test,Minimum_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector data  = RcppDeepState_IntegerVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/autothresholdr/inst/testfiles/Minimum/AFL_Minimum/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Minimum(data);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
