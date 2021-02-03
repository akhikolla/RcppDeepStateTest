#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector newton_weib_C(NumericVector n, NumericVector ex, NumericVector tx, double r, int max_iter);

TEST(mixR_deepstate_test,newton_weib_C_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/newton_weib_C/AFL_newton_weib_C/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ex  = RcppDeepState_NumericVector();
  std::string ex_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/newton_weib_C/AFL_newton_weib_C/afl_inputs/" + std::to_string(t) + "_ex.qs";
  qs::c_qsave(ex,ex_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ex values: "<< ex << std::endl;
  NumericVector tx  = RcppDeepState_NumericVector();
  std::string tx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/newton_weib_C/AFL_newton_weib_C/afl_inputs/" + std::to_string(t) + "_tx.qs";
  qs::c_qsave(tx,tx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tx values: "<< tx << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/newton_weib_C/AFL_newton_weib_C/afl_inputs/" + std::to_string(t) + "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  IntegerVector max_iter(1);
  max_iter[0]  = RcppDeepState_int();
  std::string max_iter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/newton_weib_C/AFL_newton_weib_C/afl_inputs/" + std::to_string(t) + "_max_iter.qs";
  qs::c_qsave(max_iter,max_iter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_iter values: "<< max_iter << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    newton_weib_C(n,ex,tx,r[0],max_iter[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
