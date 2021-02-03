#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getvvv(int fam, int K, int mixes, int delt, Rcpp::NumericMatrix y, Rcpp::NumericVector ppp, Rcpp::NumericVector theta1, Rcpp::NumericVector theta2, Rcpp::NumericVector z);

TEST(NHMM_deepstate_test,rcpp_getvvv_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  std::string fam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_fam.qs";
  qs::c_qsave(fam,fam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector mixes(1);
  mixes[0]  = RcppDeepState_int();
  std::string mixes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_mixes.qs";
  qs::c_qsave(mixes,mixes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mixes values: "<< mixes << std::endl;
  IntegerVector delt(1);
  delt[0]  = RcppDeepState_int();
  std::string delt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_delt.qs";
  qs::c_qsave(delt,delt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delt values: "<< delt << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector ppp  = RcppDeepState_NumericVector();
  std::string ppp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_ppp.qs";
  qs::c_qsave(ppp,ppp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppp values: "<< ppp << std::endl;
  NumericVector theta1  = RcppDeepState_NumericVector();
  std::string theta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_theta1.qs";
  qs::c_qsave(theta1,theta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta1 values: "<< theta1 << std::endl;
  NumericVector theta2  = RcppDeepState_NumericVector();
  std::string theta2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_theta2.qs";
  qs::c_qsave(theta2,theta2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta2 values: "<< theta2 << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getvvv/AFL_rcpp_getvvv/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getvvv(fam[0],K[0],mixes[0],delt[0],y,ppp,theta1,theta2,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
