#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ClustMeans(int nclust, IntegerVector start, NumericMatrix data);

TEST(lsbclust_deepstate_test,ClustMeans_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nclust(1);
  nclust[0]  = RcppDeepState_int();
  std::string nclust_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/AFL_ClustMeans/afl_inputs/" + std::to_string(t) + "_nclust.qs";
  qs::c_qsave(nclust,nclust_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nclust values: "<< nclust << std::endl;
  IntegerVector start  = RcppDeepState_IntegerVector();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/AFL_ClustMeans/afl_inputs/" + std::to_string(t) + "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/AFL_ClustMeans/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ClustMeans(nclust[0],start,data);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
