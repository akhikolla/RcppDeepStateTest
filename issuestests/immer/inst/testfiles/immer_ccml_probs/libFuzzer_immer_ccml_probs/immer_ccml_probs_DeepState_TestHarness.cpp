#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_ccml_probs(Rcpp::NumericMatrix b, Rcpp::NumericVector ll_index1, Rcpp::NumericVector item10, Rcpp::NumericVector item20, Rcpp::NumericVector cat1, Rcpp::NumericVector cat2, int max_ll_index);

TEST(immer_deepstate_test,immer_ccml_probs_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix b  = RcppDeepState_NumericMatrix();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector ll_index1  = RcppDeepState_NumericVector();
  std::string ll_index1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ll_index1.qs";
  qs::c_qsave(ll_index1,ll_index1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ll_index1 values: "<< ll_index1 << std::endl;
  NumericVector item10  = RcppDeepState_NumericVector();
  std::string item10_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_item10.qs";
  qs::c_qsave(item10,item10_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "item10 values: "<< item10 << std::endl;
  NumericVector item20  = RcppDeepState_NumericVector();
  std::string item20_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_item20.qs";
  qs::c_qsave(item20,item20_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "item20 values: "<< item20 << std::endl;
  NumericVector cat1  = RcppDeepState_NumericVector();
  std::string cat1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cat1.qs";
  qs::c_qsave(cat1,cat1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cat1 values: "<< cat1 << std::endl;
  NumericVector cat2  = RcppDeepState_NumericVector();
  std::string cat2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cat2.qs";
  qs::c_qsave(cat2,cat2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cat2 values: "<< cat2 << std::endl;
  IntegerVector max_ll_index(1);
  max_ll_index[0]  = RcppDeepState_int();
  std::string max_ll_index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_probs/libFuzzer_immer_ccml_probs/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_ll_index.qs";
  qs::c_qsave(max_ll_index,max_ll_index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_ll_index values: "<< max_ll_index << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_ccml_probs(b,ll_index1,item10,item20,cat1,cat2,max_ll_index[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
