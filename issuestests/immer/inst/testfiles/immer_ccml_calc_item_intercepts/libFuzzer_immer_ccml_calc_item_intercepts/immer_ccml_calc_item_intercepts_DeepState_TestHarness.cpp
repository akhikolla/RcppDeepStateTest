#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericMatrix immer_ccml_calc_item_intercepts(Rcpp::NumericMatrix b_fixed, Rcpp::NumericVector A_, Rcpp::NumericVector par);

TEST(immer_deepstate_test,immer_ccml_calc_item_intercepts_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix b_fixed  = RcppDeepState_NumericMatrix();
  std::string b_fixed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_calc_item_intercepts/libFuzzer_immer_ccml_calc_item_intercepts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b_fixed.qs";
  qs::c_qsave(b_fixed,b_fixed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b_fixed values: "<< b_fixed << std::endl;
  NumericVector A_  = RcppDeepState_NumericVector();
  std::string A__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_calc_item_intercepts/libFuzzer_immer_ccml_calc_item_intercepts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_A_.qs";
  qs::c_qsave(A_,A__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A_ values: "<< A_ << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  std::string par_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_calc_item_intercepts/libFuzzer_immer_ccml_calc_item_intercepts/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_par.qs";
  qs::c_qsave(par,par_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_ccml_calc_item_intercepts(b_fixed,A_,par);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
