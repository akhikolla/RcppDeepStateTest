#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double loglikTB(NumericVector parm, NumericMatrix Dm, NumericMatrix TXmat);

TEST(icensmis_deepstate_test,loglikTB_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  std::string parm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglikTB/AFL_loglikTB/afl_inputs/" + std::to_string(t) + "_parm.qs";
  qs::c_qsave(parm,parm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  std::string Dm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglikTB/AFL_loglikTB/afl_inputs/" + std::to_string(t) + "_Dm.qs";
  qs::c_qsave(Dm,Dm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericMatrix TXmat  = RcppDeepState_NumericMatrix();
  std::string TXmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglikTB/AFL_loglikTB/afl_inputs/" + std::to_string(t) + "_TXmat.qs";
  qs::c_qsave(TXmat,TXmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TXmat values: "<< TXmat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    loglikTB(parm,Dm,TXmat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
