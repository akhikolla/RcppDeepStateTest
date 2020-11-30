#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector splitpt(NumericMatrix Dmat, NumericVector x, NumericVector parm);

TEST(icRSF_deepstate_test,splitpt_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Dmat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dmat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/splitpt/inputs/Dmat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dmat values: "<< Dmat << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/splitpt/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  qs::c_qsave(parm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/splitpt/inputs/parm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    splitpt(Dmat,x,parm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
