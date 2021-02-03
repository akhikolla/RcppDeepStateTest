#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP emBB(NumericVector y, NumericMatrix gen, double df, double R2, double Pi);

TEST(NAM_deepstate_test,emBB_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBB/AFL_emBB/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix gen  = RcppDeepState_NumericMatrix();
  std::string gen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBB/AFL_emBB/afl_inputs/" + std::to_string(t) + "_gen.qs";
  qs::c_qsave(gen,gen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gen values: "<< gen << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  std::string df_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBB/AFL_emBB/afl_inputs/" + std::to_string(t) + "_df.qs";
  qs::c_qsave(df,df_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector R2(1);
  R2[0]  = RcppDeepState_double();
  std::string R2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBB/AFL_emBB/afl_inputs/" + std::to_string(t) + "_R2.qs";
  qs::c_qsave(R2,R2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R2 values: "<< R2 << std::endl;
  NumericVector Pi(1);
  Pi[0]  = RcppDeepState_double();
  std::string Pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/emBB/AFL_emBB/afl_inputs/" + std::to_string(t) + "_Pi.qs";
  qs::c_qsave(Pi,Pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Pi values: "<< Pi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    emBB(y,gen,df[0],R2[0],Pi[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
