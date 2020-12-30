#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double fuzzy_threshold(Rcpp::NumericVector imhist, Rcpp::NumericVector interval, int n, int maxiter, double omegamax, double omegamin, double c1, double c2, double mutrate, double vmax, int localsearch);

TEST(imagerExtra_deepstate_test,fuzzy_threshold_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector imhist  = RcppDeepState_NumericVector();
  qs::c_qsave(imhist,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/imhist.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "imhist values: "<< imhist << std::endl;
  NumericVector interval  = RcppDeepState_NumericVector();
  qs::c_qsave(interval,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/interval.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interval values: "<< interval << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector maxiter(1);
  maxiter[0]  = RcppDeepState_int();
  qs::c_qsave(maxiter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/maxiter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxiter values: "<< maxiter << std::endl;
  NumericVector omegamax(1);
  omegamax[0]  = RcppDeepState_double();
  qs::c_qsave(omegamax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/omegamax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omegamax values: "<< omegamax << std::endl;
  NumericVector omegamin(1);
  omegamin[0]  = RcppDeepState_double();
  qs::c_qsave(omegamin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/omegamin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omegamin values: "<< omegamin << std::endl;
  NumericVector c1(1);
  c1[0]  = RcppDeepState_double();
  qs::c_qsave(c1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/c1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c1 values: "<< c1 << std::endl;
  NumericVector c2(1);
  c2[0]  = RcppDeepState_double();
  qs::c_qsave(c2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/c2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c2 values: "<< c2 << std::endl;
  NumericVector mutrate(1);
  mutrate[0]  = RcppDeepState_double();
  qs::c_qsave(mutrate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/mutrate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mutrate values: "<< mutrate << std::endl;
  NumericVector vmax(1);
  vmax[0]  = RcppDeepState_double();
  qs::c_qsave(vmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/vmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vmax values: "<< vmax << std::endl;
  IntegerVector localsearch(1);
  localsearch[0]  = RcppDeepState_int();
  qs::c_qsave(localsearch,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/fuzzy_threshold/inputs/localsearch.qs",
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
