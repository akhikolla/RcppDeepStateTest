#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double loglik_lamb(NumericVector par, NumericMatrix Dm, NumericVector eta);

TEST(icensmis_deepstate_test,loglik_lamb_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  qs::c_qsave(par,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglik_lamb/inputs/par.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglik_lamb/inputs/Dm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericVector eta  = RcppDeepState_NumericVector();
  qs::c_qsave(eta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/loglik_lamb/inputs/eta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    loglik_lamb(par,Dm,eta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
