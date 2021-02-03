#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector coordToIndex(IntegerVector row, IntegerVector col, const int N);

TEST(propr_deepstate_test,coordToIndex_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector row  = RcppDeepState_IntegerVector();
  std::string row_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/AFL_coordToIndex/afl_inputs/" + std::to_string(t) + "_row.qs";
  qs::c_qsave(row,row_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "row values: "<< row << std::endl;
  IntegerVector col  = RcppDeepState_IntegerVector();
  std::string col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/AFL_coordToIndex/afl_inputs/" + std::to_string(t) + "_col.qs";
  qs::c_qsave(col,col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/AFL_coordToIndex/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    coordToIndex(row,col,N[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
