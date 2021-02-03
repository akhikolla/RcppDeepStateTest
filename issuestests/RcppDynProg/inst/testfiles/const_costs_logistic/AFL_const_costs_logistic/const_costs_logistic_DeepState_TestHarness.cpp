#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix const_costs_logistic(NumericVector y, NumericVector w, const int min_seg, IntegerVector indices);

TEST(RcppDynProg_deepstate_test,const_costs_logistic_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/const_costs_logistic/AFL_const_costs_logistic/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/const_costs_logistic/AFL_const_costs_logistic/afl_inputs/" + std::to_string(t) + "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector min_seg(1);
  min_seg[0]  = RcppDeepState_int();
  std::string min_seg_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/const_costs_logistic/AFL_const_costs_logistic/afl_inputs/" + std::to_string(t) + "_min_seg.qs";
  qs::c_qsave(min_seg,min_seg_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_seg values: "<< min_seg << std::endl;
  IntegerVector indices  = RcppDeepState_IntegerVector();
  std::string indices_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RcppDynProg/inst/testfiles/const_costs_logistic/AFL_const_costs_logistic/afl_inputs/" + std::to_string(t) + "_indices.qs";
  qs::c_qsave(indices,indices_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "indices values: "<< indices << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    const_costs_logistic(y,w,min_seg[0],indices);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
