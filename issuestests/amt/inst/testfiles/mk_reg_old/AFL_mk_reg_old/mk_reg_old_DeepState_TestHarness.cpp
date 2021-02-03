#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector mk_reg_old(NumericVector relocs_time, int time_dist, int time_tol, int start);

TEST(amt_deepstate_test,mk_reg_old_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector relocs_time  = RcppDeepState_NumericVector();
  std::string relocs_time_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg_old/AFL_mk_reg_old/afl_inputs/" + std::to_string(t) + "_relocs_time.qs";
  qs::c_qsave(relocs_time,relocs_time_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "relocs_time values: "<< relocs_time << std::endl;
  IntegerVector time_dist(1);
  time_dist[0]  = RcppDeepState_int();
  std::string time_dist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg_old/AFL_mk_reg_old/afl_inputs/" + std::to_string(t) + "_time_dist.qs";
  qs::c_qsave(time_dist,time_dist_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_dist values: "<< time_dist << std::endl;
  IntegerVector time_tol(1);
  time_tol[0]  = RcppDeepState_int();
  std::string time_tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg_old/AFL_mk_reg_old/afl_inputs/" + std::to_string(t) + "_time_tol.qs";
  qs::c_qsave(time_tol,time_tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_tol values: "<< time_tol << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg_old/AFL_mk_reg_old/afl_inputs/" + std::to_string(t) + "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mk_reg_old(relocs_time,time_dist[0],time_tol[0],start[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
