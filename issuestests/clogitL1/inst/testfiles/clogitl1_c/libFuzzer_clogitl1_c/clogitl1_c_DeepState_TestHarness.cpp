#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clogitl1_c(NumericVector n, NumericVector m, NumericMatrix Xmat, NumericVector yvec, int switchIter, int numLambda, double minLambda, double alpha);

TEST(clogitL1_deepstate_test,clogitl1_c_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector m  = RcppDeepState_NumericVector();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m.qs";
  qs::c_qsave(m,m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  std::string Xmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xmat.qs";
  qs::c_qsave(Xmat,Xmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  NumericVector yvec  = RcppDeepState_NumericVector();
  std::string yvec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yvec.qs";
  qs::c_qsave(yvec,yvec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yvec values: "<< yvec << std::endl;
  IntegerVector switchIter(1);
  switchIter[0]  = RcppDeepState_int();
  std::string switchIter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_switchIter.qs";
  qs::c_qsave(switchIter,switchIter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "switchIter values: "<< switchIter << std::endl;
  IntegerVector numLambda(1);
  numLambda[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  std::string numLambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_numLambda.qs";
  qs::c_qsave(numLambda,numLambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numLambda values: "<< numLambda << std::endl;
  NumericVector minLambda(1);
  minLambda[0]  = RcppDeepState_double();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m.qs";
  std::string minLambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_minLambda.qs";
  qs::c_qsave(minLambda,minLambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "minLambda values: "<< minLambda << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1_c/libFuzzer_clogitl1_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clogitl1_c(n,m,Xmat,yvec,switchIter[0],numLambda[0],minLambda[0],alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
