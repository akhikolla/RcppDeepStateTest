#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector saturateim(Rcpp::NumericVector data, double max_im, double min_im, double max_range, double min_range);

TEST(imagerExtra_deepstate_test,saturateim_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/saturateim/AFL_saturateim/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector max_im(1);
  max_im[0]  = RcppDeepState_double();
  std::string max_im_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/saturateim/AFL_saturateim/afl_inputs/" + std::to_string(t) + "_max_im.qs";
  qs::c_qsave(max_im,max_im_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_im values: "<< max_im << std::endl;
  NumericVector min_im(1);
  min_im[0]  = RcppDeepState_double();
  std::string min_im_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/saturateim/AFL_saturateim/afl_inputs/" + std::to_string(t) + "_min_im.qs";
  qs::c_qsave(min_im,min_im_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_im values: "<< min_im << std::endl;
  NumericVector max_range(1);
  max_range[0]  = RcppDeepState_double();
  std::string max_range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/saturateim/AFL_saturateim/afl_inputs/" + std::to_string(t) + "_max_range.qs";
  qs::c_qsave(max_range,max_range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_range values: "<< max_range << std::endl;
  NumericVector min_range(1);
  min_range[0]  = RcppDeepState_double();
  std::string min_range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/saturateim/AFL_saturateim/afl_inputs/" + std::to_string(t) + "_min_range.qs";
  qs::c_qsave(min_range,min_range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_range values: "<< min_range << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    saturateim(data,max_im[0],min_im[0],max_range[0],min_range[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
