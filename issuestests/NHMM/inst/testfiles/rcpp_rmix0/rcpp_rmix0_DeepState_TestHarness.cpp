#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_rmix0(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2);

TEST(NHMM_deepstate_test,rcpp_rmix0_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  qs::c_qsave(fam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix0/inputs/fam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  NumericVector ppp  = RcppDeepState_NumericVector();
  qs::c_qsave(ppp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix0/inputs/ppp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppp values: "<< ppp << std::endl;
  NumericVector par1  = RcppDeepState_NumericVector();
  qs::c_qsave(par1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix0/inputs/par1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par1 values: "<< par1 << std::endl;
  NumericVector par2  = RcppDeepState_NumericVector();
  qs::c_qsave(par2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix0/inputs/par2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par2 values: "<< par2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_rmix0(fam[0],ppp,par1,par2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
