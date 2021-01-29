#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector funX(NumericVector col, int finsiz);

TEST(NAM_deepstate_test,funX_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  std::string col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funX/libFuzzer_funX/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_col.qs";
  qs::c_qsave(col,col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector finsiz(1);
  finsiz[0]  = RcppDeepState_int();
  std::string finsiz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funX/libFuzzer_funX/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_finsiz.qs";
  qs::c_qsave(finsiz,finsiz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "finsiz values: "<< finsiz << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    funX(col,finsiz[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
