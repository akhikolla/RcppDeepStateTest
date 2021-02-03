#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix var_pillars(NumericVector arr3d);

TEST(autothresholdr_deepstate_test,var_pillars_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector arr3d  = RcppDeepState_NumericVector();
  std::string arr3d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/autothresholdr/inst/testfiles/var_pillars/AFL_var_pillars/afl_inputs/" + std::to_string(t) + "_arr3d.qs";
  qs::c_qsave(arr3d,arr3d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "arr3d values: "<< arr3d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    var_pillars(arr3d);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
