#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix threshold_adaptive(Rcpp::NumericMatrix mat, double k, int windowsize, double maxsd);

TEST(imagerExtra_deepstate_test,threshold_adaptive_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(mat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/inputs/mat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  qs::c_qsave(k,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/inputs/k.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  IntegerVector windowsize(1);
  windowsize[0]  = RcppDeepState_int();
  qs::c_qsave(windowsize,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/inputs/windowsize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowsize values: "<< windowsize << std::endl;
  NumericVector maxsd(1);
  maxsd[0]  = RcppDeepState_double();
  qs::c_qsave(maxsd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/inputs/maxsd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxsd values: "<< maxsd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    threshold_adaptive(mat,k[0],windowsize[0],maxsd[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
