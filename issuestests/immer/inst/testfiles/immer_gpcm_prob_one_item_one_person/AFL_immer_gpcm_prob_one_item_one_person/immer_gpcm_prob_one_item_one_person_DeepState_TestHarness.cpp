#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_gpcm_prob_one_item_one_person(double theta1, Rcpp::NumericVector b_ii, double a);

TEST(immer_deepstate_test,immer_gpcm_prob_one_item_one_person_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector theta1(1);
  theta1[0]  = RcppDeepState_double();
  std::string theta1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_gpcm_prob_one_item_one_person/AFL_immer_gpcm_prob_one_item_one_person/afl_inputs/" + std::to_string(t) + "_theta1.qs";
  qs::c_qsave(theta1,theta1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta1 values: "<< theta1 << std::endl;
  NumericVector b_ii  = RcppDeepState_NumericVector();
  std::string b_ii_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_gpcm_prob_one_item_one_person/AFL_immer_gpcm_prob_one_item_one_person/afl_inputs/" + std::to_string(t) + "_b_ii.qs";
  qs::c_qsave(b_ii,b_ii_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b_ii values: "<< b_ii << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_gpcm_prob_one_item_one_person/AFL_immer_gpcm_prob_one_item_one_person/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_gpcm_prob_one_item_one_person(theta1[0],b_ii,a[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
