#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector qsplitt(NumericVector p, NumericVector mu, NumericVector df, NumericVector phi, NumericVector lmd);

TEST(dng_deepstate_test,qsplitt_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector p  = RcppDeepState_NumericVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericVector mu  = RcppDeepState_NumericVector();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector df  = RcppDeepState_NumericVector();
  std::string df_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_df.qs";
  qs::c_qsave(df,df_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector lmd  = RcppDeepState_NumericVector();
  std::string lmd_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/qsplitt/libFuzzer_qsplitt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lmd.qs";
  qs::c_qsave(lmd,lmd_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lmd values: "<< lmd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    qsplitt(p,mu,df,phi,lmd);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
