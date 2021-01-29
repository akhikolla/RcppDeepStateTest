#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP emBA(NumericVector y, NumericMatrix gen, double df, double R2);

TEST(NAM_deepstate_test,emBA_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBA/libFuzzer_emBA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix gen  = RcppDeepState_NumericMatrix();
  std::string gen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBA/libFuzzer_emBA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gen.qs";
  qs::c_qsave(gen,gen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gen values: "<< gen << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  std::string df_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBA/libFuzzer_emBA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_df.qs";
  qs::c_qsave(df,df_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector R2(1);
  R2[0]  = RcppDeepState_double();
  std::string R2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBA/libFuzzer_emBA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_R2.qs";
  qs::c_qsave(R2,R2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R2 values: "<< R2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    emBA(y,gen,df[0],R2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
