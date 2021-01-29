#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void SAMP2(NumericMatrix X, NumericVector g, NumericVector y, NumericVector xx, NumericVector E, NumericVector L, int N, double Ve);

TEST(NAM_deepstate_test,SAMP2_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector g  = RcppDeepState_NumericVector();
  std::string g_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_g.qs";
  qs::c_qsave(g,g_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector xx  = RcppDeepState_NumericVector();
  std::string xx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xx.qs";
  qs::c_qsave(xx,xx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xx values: "<< xx << std::endl;
  NumericVector E  = RcppDeepState_NumericVector();
  std::string E_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_E.qs";
  qs::c_qsave(E,E_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "E values: "<< E << std::endl;
  NumericVector L  = RcppDeepState_NumericVector();
  std::string L_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_L.qs";
  qs::c_qsave(L,L_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector Ve(1);
  Ve[0]  = RcppDeepState_double();
  std::string Ve_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP2/libFuzzer_SAMP2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Ve.qs";
  qs::c_qsave(Ve,Ve_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ve values: "<< Ve << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SAMP2(X,g,y,xx,E,L,N[0],Ve[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
