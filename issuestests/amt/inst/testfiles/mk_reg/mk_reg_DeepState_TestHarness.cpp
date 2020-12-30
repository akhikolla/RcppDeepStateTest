#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector mk_reg(NumericVector t1, int time_dist, int time_tol, int start);

TEST(amt_deepstate_test,mk_reg_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector t1  = RcppDeepState_NumericVector();
  qs::c_qsave(t1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg/inputs/t1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  IntegerVector time_dist(1);
  time_dist[0]  = RcppDeepState_int();
  qs::c_qsave(time_dist,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg/inputs/time_dist.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_dist values: "<< time_dist << std::endl;
  IntegerVector time_tol(1);
  time_tol[0]  = RcppDeepState_int();
  qs::c_qsave(time_tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg/inputs/time_tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_tol values: "<< time_tol << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/mk_reg/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mk_reg(t1,time_dist[0],time_tol[0],start[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
