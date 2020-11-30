#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clogitl1CV_c(NumericVector n, NumericVector m, NumericMatrix Xmat, NumericVector yvec, NumericVector lambdas, NumericVector keepvec, double alpha);

TEST(clogitL1_deepstate_test,clogitl1CV_c_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector m  = RcppDeepState_NumericVector();
  qs::c_qsave(m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xmat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/Xmat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  NumericVector yvec  = RcppDeepState_NumericVector();
  qs::c_qsave(yvec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/yvec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yvec values: "<< yvec << std::endl;
  NumericVector lambdas  = RcppDeepState_NumericVector();
  qs::c_qsave(lambdas,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/lambdas.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdas values: "<< lambdas << std::endl;
  NumericVector keepvec  = RcppDeepState_NumericVector();
  qs::c_qsave(keepvec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/keepvec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "keepvec values: "<< keepvec << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clogitl1CV_c(n,m,Xmat,yvec,lambdas,keepvec,alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
