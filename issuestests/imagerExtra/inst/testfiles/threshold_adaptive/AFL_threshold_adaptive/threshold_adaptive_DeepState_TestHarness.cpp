#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix threshold_adaptive(Rcpp::NumericMatrix mat, double k, int windowsize, double maxsd);

TEST(imagerExtra_deepstate_test,threshold_adaptive_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix mat  = RcppDeepState_NumericMatrix();
  std::string mat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/AFL_threshold_adaptive/afl_inputs/" + std::to_string(t) + "_mat.qs";
  qs::c_qsave(mat,mat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mat values: "<< mat << std::endl;
  NumericVector k(1);
  k[0]  = RcppDeepState_double();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/AFL_threshold_adaptive/afl_inputs/" + std::to_string(t) + "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  IntegerVector windowsize(1);
  windowsize[0]  = RcppDeepState_int();
  std::string windowsize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/AFL_threshold_adaptive/afl_inputs/" + std::to_string(t) + "_windowsize.qs";
  qs::c_qsave(windowsize,windowsize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowsize values: "<< windowsize << std::endl;
  NumericVector maxsd(1);
  maxsd[0]  = RcppDeepState_double();
  std::string maxsd_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/threshold_adaptive/AFL_threshold_adaptive/afl_inputs/" + std::to_string(t) + "_maxsd.qs";
  qs::c_qsave(maxsd,maxsd_t,
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
