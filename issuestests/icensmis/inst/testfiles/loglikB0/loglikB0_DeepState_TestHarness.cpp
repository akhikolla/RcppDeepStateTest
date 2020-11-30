#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double loglikB0(NumericVector parm1, NumericMatrix Dm);

TEST(icensmis_deepstate_test,loglikB0_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector parm1  = RcppDeepState_NumericVector();
  qs::c_qsave(parm1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglikB0/inputs/parm1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm1 values: "<< parm1 << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglikB0/inputs/Dm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    loglikB0(parm1,Dm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
