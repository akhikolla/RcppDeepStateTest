#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector matMultinom(Rcpp::NumericMatrix probmatrix);

TEST(simstudy_deepstate_test,matMultinom_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix probmatrix  = RcppDeepState_NumericMatrix();
  std::string probmatrix_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/matMultinom/libFuzzer_matMultinom/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_probmatrix.qs";
  qs::c_qsave(probmatrix,probmatrix_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probmatrix values: "<< probmatrix << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    matMultinom(probmatrix);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
