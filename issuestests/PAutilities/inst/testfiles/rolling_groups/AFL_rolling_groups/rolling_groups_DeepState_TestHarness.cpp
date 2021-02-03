#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List rolling_groups(IntegerVector values, int n);

TEST(PAutilities_deepstate_test,rolling_groups_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector values  = RcppDeepState_IntegerVector();
  std::string values_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/rolling_groups/AFL_rolling_groups/afl_inputs/" + std::to_string(t) + "_values.qs";
  qs::c_qsave(values,values_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "values values: "<< values << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/rolling_groups/AFL_rolling_groups/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rolling_groups(values,n[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
