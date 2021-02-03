#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector cpCI(int n_tot, int n_suc, double conf);

TEST(rbscCI_deepstate_test,cpCI_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n_tot(1);
  n_tot[0]  = RcppDeepState_int();
  std::string n_tot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/cpCI/AFL_cpCI/afl_inputs/" + std::to_string(t) + "_n_tot.qs";
  qs::c_qsave(n_tot,n_tot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_tot values: "<< n_tot << std::endl;
  IntegerVector n_suc(1);
  n_suc[0]  = RcppDeepState_int();
  std::string n_suc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/cpCI/AFL_cpCI/afl_inputs/" + std::to_string(t) + "_n_suc.qs";
  qs::c_qsave(n_suc,n_suc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_suc values: "<< n_suc << std::endl;
  NumericVector conf(1);
  conf[0]  = RcppDeepState_double();
  std::string conf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/cpCI/AFL_cpCI/afl_inputs/" + std::to_string(t) + "_conf.qs";
  qs::c_qsave(conf,conf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "conf values: "<< conf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpCI(n_tot[0],n_suc[0],conf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
