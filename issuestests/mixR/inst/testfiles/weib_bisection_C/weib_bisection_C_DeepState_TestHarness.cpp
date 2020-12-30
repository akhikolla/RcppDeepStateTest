#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector weib_bisection_C(NumericVector n, NumericVector ex, NumericVector tx, double tol, int max_iter, double xleft, double xright);

TEST(mixR_deepstate_test,weib_bisection_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ex  = RcppDeepState_NumericVector();
  qs::c_qsave(ex,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/ex.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ex values: "<< ex << std::endl;
  NumericVector tx  = RcppDeepState_NumericVector();
  qs::c_qsave(tx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/tx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tx values: "<< tx << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  qs::c_qsave(tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  IntegerVector max_iter(1);
  max_iter[0]  = RcppDeepState_int();
  qs::c_qsave(max_iter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/max_iter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_iter values: "<< max_iter << std::endl;
  NumericVector xleft(1);
  xleft[0]  = RcppDeepState_double();
  qs::c_qsave(xleft,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/xleft.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xleft values: "<< xleft << std::endl;
  NumericVector xright(1);
  xright[0]  = RcppDeepState_double();
  qs::c_qsave(xright,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/inputs/xright.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xright values: "<< xright << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    weib_bisection_C(n,ex,tx,tol[0],max_iter[0],xleft[0],xright[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
