#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ccor(int k, int j, int c, NumericVector seq, int M, NumericMatrix csim);

TEST(segmenTier_deepstate_test,ccor_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  std::string j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_j.qs";
  qs::c_qsave(j,j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  IntegerVector c(1);
  c[0]  = RcppDeepState_int();
  std::string c_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_c.qs";
  qs::c_qsave(c,c_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  NumericVector seq  = RcppDeepState_NumericVector();
  std::string seq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seq.qs";
  qs::c_qsave(seq,seq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq values: "<< seq << std::endl;
  IntegerVector M(1);
  M[0]  = RcppDeepState_int();
  std::string M_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_M.qs";
  qs::c_qsave(M,M_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericMatrix csim  = RcppDeepState_NumericMatrix();
  std::string c_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_c.qs";
  std::string csim_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/ccor/libFuzzer_ccor/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_csim.qs";
  qs::c_qsave(csim,csim_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "csim values: "<< csim << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ccor(k[0],j[0],c[0],seq,M[0],csim);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
