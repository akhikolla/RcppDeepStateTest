#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector piecewise_transformation(Rcpp::NumericVector data, Rcpp::NumericVector F, int N, double smax, double smin, double max, double min, double max_range, double min_range);

TEST(imagerExtra_deepstate_test,piecewise_transformation_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector F  = RcppDeepState_NumericVector();
  std::string F_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_F.qs";
  qs::c_qsave(F,F_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "F values: "<< F << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector smax(1);
  smax[0]  = RcppDeepState_double();
  std::string smax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_smax.qs";
  qs::c_qsave(smax,smax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "smax values: "<< smax << std::endl;
  NumericVector smin(1);
  smin[0]  = RcppDeepState_double();
  std::string smin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_smin.qs";
  qs::c_qsave(smin,smin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "smin values: "<< smin << std::endl;
  NumericVector max(1);
  max[0]  = RcppDeepState_double();
  std::string max_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_max.qs";
  qs::c_qsave(max,max_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max values: "<< max << std::endl;
  NumericVector min(1);
  min[0]  = RcppDeepState_double();
  std::string min_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_min.qs";
  qs::c_qsave(min,min_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min values: "<< min << std::endl;
  NumericVector max_range(1);
  max_range[0]  = RcppDeepState_double();
  std::string max_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_max.qs";
  std::string max_range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_max_range.qs";
  qs::c_qsave(max_range,max_range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_range values: "<< max_range << std::endl;
  NumericVector min_range(1);
  min_range[0]  = RcppDeepState_double();
  std::string min_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_min.qs";
  std::string min_range_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/piecewise_transformation/AFL_piecewise_transformation/afl_inputs/" + std::to_string(t) + "_min_range.qs";
  qs::c_qsave(min_range,min_range_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_range values: "<< min_range << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    piecewise_transformation(data,F,N[0],smax[0],smin[0],max[0],min[0],max_range[0],min_range[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
