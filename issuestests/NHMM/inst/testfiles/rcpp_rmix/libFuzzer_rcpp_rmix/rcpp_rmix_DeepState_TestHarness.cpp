#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_rmix(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2);

TEST(NHMM_deepstate_test,rcpp_rmix_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  std::string fam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix/libFuzzer_rcpp_rmix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fam.qs";
  qs::c_qsave(fam,fam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  NumericVector ppp  = RcppDeepState_NumericVector();
  std::string ppp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix/libFuzzer_rcpp_rmix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ppp.qs";
  qs::c_qsave(ppp,ppp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppp values: "<< ppp << std::endl;
  NumericVector par1  = RcppDeepState_NumericVector();
  std::string par1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix/libFuzzer_rcpp_rmix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_par1.qs";
  qs::c_qsave(par1,par1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par1 values: "<< par1 << std::endl;
  NumericVector par2  = RcppDeepState_NumericVector();
  std::string par2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_rmix/libFuzzer_rcpp_rmix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_par2.qs";
  qs::c_qsave(par2,par2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par2 values: "<< par2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_rmix(fam[0],ppp,par1,par2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
