#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector simulate_udf(int n_steps, int start, int nc, int nr, NumericMatrix mk, NumericMatrix hk);

TEST(amt_deepstate_test,simulate_udf_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  std::string n_steps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_n_steps.qs";
  qs::c_qsave(n_steps,n_steps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  IntegerVector nc(1);
  nc[0]  = RcppDeepState_int();
  std::string nc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_nc.qs";
  qs::c_qsave(nc,nc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nc values: "<< nc << std::endl;
  IntegerVector nr(1);
  nr[0]  = RcppDeepState_int();
  std::string nr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_nr.qs";
  qs::c_qsave(nr,nr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr values: "<< nr << std::endl;
  NumericMatrix mk  = RcppDeepState_NumericMatrix();
  std::string mk_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_mk.qs";
  qs::c_qsave(mk,mk_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mk values: "<< mk << std::endl;
  NumericMatrix hk  = RcppDeepState_NumericMatrix();
  std::string hk_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/AFL_simulate_udf/afl_inputs/" + std::to_string(t) + "_hk.qs";
  qs::c_qsave(hk,hk_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hk values: "<< hk << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    simulate_udf(n_steps[0],start[0],nc[0],nr[0],mk,hk);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
