#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List myfitConGraphC(NumericMatrix amat, NumericMatrix S, double n, double tol);

TEST(robFitConGraph_deepstate_test,myfitConGraphC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix amat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(amat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/inputs/amat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "amat values: "<< amat << std::endl;
  NumericMatrix S  = RcppDeepState_NumericMatrix();
  qs::c_qsave(S,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/inputs/S.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "S values: "<< S << std::endl;
  NumericVector n(1);
  n[0]  = RcppDeepState_double();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  qs::c_qsave(tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/inputs/tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    myfitConGraphC(amat,S,n[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
