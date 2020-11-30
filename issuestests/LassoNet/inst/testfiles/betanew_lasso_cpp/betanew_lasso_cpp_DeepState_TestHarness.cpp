#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List betanew_lasso_cpp(NumericMatrix xx, NumericVector xy, NumericVector beta, NumericMatrix M, NumericVector y, double Lambda1, double Lambda2, double iter, double tol);

TEST(LassoNet_deepstate_test,betanew_lasso_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix xx  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/xx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xx values: "<< xx << std::endl;
  NumericVector xy  = RcppDeepState_NumericVector();
  qs::c_qsave(xy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/xy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xy values: "<< xy << std::endl;
  NumericVector beta  = RcppDeepState_NumericVector();
  qs::c_qsave(beta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/beta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  qs::c_qsave(M,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/M.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector Lambda1(1);
  Lambda1[0]  = RcppDeepState_double();
  qs::c_qsave(Lambda1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/Lambda1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda1 values: "<< Lambda1 << std::endl;
  NumericVector Lambda2(1);
  Lambda2[0]  = RcppDeepState_double();
  qs::c_qsave(Lambda2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/Lambda2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda2 values: "<< Lambda2 << std::endl;
  NumericVector iter(1);
  iter[0]  = RcppDeepState_double();
  qs::c_qsave(iter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/iter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iter values: "<< iter << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  qs::c_qsave(tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/inputs/tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    betanew_lasso_cpp(xx,xy,beta,M,y,Lambda1[0],Lambda2[0],iter[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
