#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_dmvnorm(Rcpp::NumericVector dataf, Rcpp::NumericVector meanf, Rcpp::NumericMatrix Siginvf, double detf);

TEST(NHMM_deepstate_test,rcpp_dmvnorm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector dataf  = RcppDeepState_NumericVector();
  std::string dataf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/AFL_rcpp_dmvnorm/afl_inputs/" + std::to_string(t) + "_dataf.qs";
  qs::c_qsave(dataf,dataf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dataf values: "<< dataf << std::endl;
  NumericVector meanf  = RcppDeepState_NumericVector();
  std::string meanf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/AFL_rcpp_dmvnorm/afl_inputs/" + std::to_string(t) + "_meanf.qs";
  qs::c_qsave(meanf,meanf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "meanf values: "<< meanf << std::endl;
  NumericMatrix Siginvf  = RcppDeepState_NumericMatrix();
  std::string Siginvf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/AFL_rcpp_dmvnorm/afl_inputs/" + std::to_string(t) + "_Siginvf.qs";
  qs::c_qsave(Siginvf,Siginvf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Siginvf values: "<< Siginvf << std::endl;
  NumericVector detf(1);
  detf[0]  = RcppDeepState_double();
  std::string detf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/AFL_rcpp_dmvnorm/afl_inputs/" + std::to_string(t) + "_detf.qs";
  qs::c_qsave(detf,detf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "detf values: "<< detf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_dmvnorm(dataf,meanf,Siginvf,detf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
