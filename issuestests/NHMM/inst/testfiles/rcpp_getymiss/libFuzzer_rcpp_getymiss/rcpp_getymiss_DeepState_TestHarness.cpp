#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix rcpp_getymiss(int fam, int K, Rcpp::NumericVector z, Rcpp::NumericVector ppp, Rcpp::NumericVector theta1, Rcpp::NumericVector theta2, int mixes, int delt, int J);

TEST(NHMM_deepstate_test,rcpp_getymiss_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  std::string fam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fam.qs";
  qs::c_qsave(fam,fam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector ppp  = RcppDeepState_NumericVector();
  std::string ppp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ppp.qs";
  qs::c_qsave(ppp,ppp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ppp values: "<< ppp << std::endl;
  NumericVector theta1  = RcppDeepState_NumericVector();
  std::string theta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta1.qs";
  qs::c_qsave(theta1,theta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta1 values: "<< theta1 << std::endl;
  NumericVector theta2  = RcppDeepState_NumericVector();
  std::string theta2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta2.qs";
  qs::c_qsave(theta2,theta2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta2 values: "<< theta2 << std::endl;
  IntegerVector mixes(1);
  mixes[0]  = RcppDeepState_int();
  std::string mixes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mixes.qs";
  qs::c_qsave(mixes,mixes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mixes values: "<< mixes << std::endl;
  IntegerVector delt(1);
  delt[0]  = RcppDeepState_int();
  std::string delt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_delt.qs";
  qs::c_qsave(delt,delt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delt values: "<< delt << std::endl;
  IntegerVector J(1);
  J[0]  = RcppDeepState_int();
  std::string J_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getymiss/libFuzzer_rcpp_getymiss/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_J.qs";
  qs::c_qsave(J,J_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getymiss(fam[0],K[0],z,ppp,theta1,theta2,mixes[0],delt[0],J[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
