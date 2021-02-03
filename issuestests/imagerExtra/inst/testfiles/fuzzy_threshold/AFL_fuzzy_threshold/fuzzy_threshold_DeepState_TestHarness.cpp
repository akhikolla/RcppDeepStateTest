#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double fuzzy_threshold(Rcpp::NumericVector imhist, Rcpp::NumericVector interval, int n, int maxiter, double omegamax, double omegamin, double c1, double c2, double mutrate, double vmax, int localsearch);

TEST(imagerExtra_deepstate_test,fuzzy_threshold_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector imhist  = RcppDeepState_NumericVector();
  std::string imhist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_imhist.qs";
  qs::c_qsave(imhist,imhist_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "imhist values: "<< imhist << std::endl;
  NumericVector interval  = RcppDeepState_NumericVector();
  std::string interval_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_interval.qs";
  qs::c_qsave(interval,interval_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interval values: "<< interval << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector maxiter(1);
  maxiter[0]  = RcppDeepState_int();
  std::string maxiter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_maxiter.qs";
  qs::c_qsave(maxiter,maxiter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxiter values: "<< maxiter << std::endl;
  NumericVector omegamax(1);
  omegamax[0]  = RcppDeepState_double();
  std::string omegamax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_omegamax.qs";
  qs::c_qsave(omegamax,omegamax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omegamax values: "<< omegamax << std::endl;
  NumericVector omegamin(1);
  omegamin[0]  = RcppDeepState_double();
  std::string omegamin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_omegamin.qs";
  qs::c_qsave(omegamin,omegamin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omegamin values: "<< omegamin << std::endl;
  NumericVector c1(1);
  c1[0]  = RcppDeepState_double();
  std::string c1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_c1.qs";
  qs::c_qsave(c1,c1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c1 values: "<< c1 << std::endl;
  NumericVector c2(1);
  c2[0]  = RcppDeepState_double();
  std::string c2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_c2.qs";
  qs::c_qsave(c2,c2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c2 values: "<< c2 << std::endl;
  NumericVector mutrate(1);
  mutrate[0]  = RcppDeepState_double();
  std::string mutrate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_mutrate.qs";
  qs::c_qsave(mutrate,mutrate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mutrate values: "<< mutrate << std::endl;
  NumericVector vmax(1);
  vmax[0]  = RcppDeepState_double();
  std::string vmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_vmax.qs";
  qs::c_qsave(vmax,vmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vmax values: "<< vmax << std::endl;
  IntegerVector localsearch(1);
  localsearch[0]  = RcppDeepState_int();
  std::string localsearch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/AFL_fuzzy_threshold/afl_inputs/" + std::to_string(t) + "_localsearch.qs";
  qs::c_qsave(localsearch,localsearch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "localsearch values: "<< localsearch << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    fuzzy_threshold(imhist,interval,n[0],maxiter[0],omegamax[0],omegamin[0],c1[0],c2[0],mutrate[0],vmax[0],localsearch[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
