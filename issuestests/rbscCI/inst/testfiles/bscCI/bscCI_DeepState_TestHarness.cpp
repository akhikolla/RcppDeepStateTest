#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bscCI(int n_tot, int n_suc, double conf);

TEST(rbscCI_deepstate_test,bscCI_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n_tot(1);
  n_tot[0]  = RcppDeepState_int();
  qs::c_qsave(n_tot,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/bscCI/inputs/n_tot.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_tot values: "<< n_tot << std::endl;
  IntegerVector n_suc(1);
  n_suc[0]  = RcppDeepState_int();
  qs::c_qsave(n_suc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/bscCI/inputs/n_suc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_suc values: "<< n_suc << std::endl;
  NumericVector conf(1);
  conf[0]  = RcppDeepState_double();
  qs::c_qsave(conf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rbscCI/inst/testfiles/bscCI/inputs/conf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "conf values: "<< conf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bscCI(n_tot[0],n_suc[0],conf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
