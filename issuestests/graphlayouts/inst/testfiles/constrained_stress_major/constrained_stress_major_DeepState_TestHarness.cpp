#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix constrained_stress_major(NumericMatrix y, int dim, NumericMatrix W, NumericMatrix D, int iter, double tol);

TEST(graphlayouts_deepstate_test,constrained_stress_major_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector dim(1);
  dim[0]  = RcppDeepState_int();
  qs::c_qsave(dim,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/dim.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dim values: "<< dim << std::endl;
  NumericMatrix W  = RcppDeepState_NumericMatrix();
  qs::c_qsave(W,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/W.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "W values: "<< W << std::endl;
  NumericMatrix D  = RcppDeepState_NumericMatrix();
  qs::c_qsave(D,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/D.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D values: "<< D << std::endl;
  IntegerVector iter(1);
  iter[0]  = RcppDeepState_int();
  qs::c_qsave(iter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/iter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iter values: "<< iter << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  qs::c_qsave(tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/graphlayouts/inst/testfiles/constrained_stress_major/inputs/tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    constrained_stress_major(y,dim[0],W,D,iter[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
