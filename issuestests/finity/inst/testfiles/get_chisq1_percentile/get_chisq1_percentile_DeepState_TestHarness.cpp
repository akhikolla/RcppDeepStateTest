#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double get_chisq1_percentile(double value);

TEST(finity_deepstate_test,get_chisq1_percentile_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector value(1);
  value[0]  = RcppDeepState_double();
  qs::c_qsave(value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/finity/inst/testfiles/get_chisq1_percentile/inputs/value.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_chisq1_percentile(value[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
