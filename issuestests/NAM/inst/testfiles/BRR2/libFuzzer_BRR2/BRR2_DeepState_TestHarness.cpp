#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP BRR2(NumericVector y, NumericMatrix X1, NumericMatrix X2, double it, double bi, double df, double R2);

TEST(NAM_deepstate_test,BRR2_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  std::string X1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X1.qs";
  qs::c_qsave(X1,X1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  NumericMatrix X2  = RcppDeepState_NumericMatrix();
  std::string X2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X2.qs";
  qs::c_qsave(X2,X2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X2 values: "<< X2 << std::endl;
  NumericVector it(1);
  it[0]  = RcppDeepState_double();
  std::string it_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_it.qs";
  qs::c_qsave(it,it_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "it values: "<< it << std::endl;
  NumericVector bi(1);
  bi[0]  = RcppDeepState_double();
  std::string bi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_bi.qs";
  qs::c_qsave(bi,bi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bi values: "<< bi << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  std::string df_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_df.qs";
  qs::c_qsave(df,df_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector R2(1);
  R2[0]  = RcppDeepState_double();
  std::string R2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BRR2/libFuzzer_BRR2/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_R2.qs";
  qs::c_qsave(R2,R2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R2 values: "<< R2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    BRR2(y,X1,X2,it[0],bi[0],df[0],R2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
