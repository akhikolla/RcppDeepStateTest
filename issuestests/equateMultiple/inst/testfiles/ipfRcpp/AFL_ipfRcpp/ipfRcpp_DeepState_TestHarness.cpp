#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ipfRcpp(NumericMatrix aj1T, int base, double eps);

TEST(equateMultiple_deepstate_test,ipfRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix aj1T  = RcppDeepState_NumericMatrix();
  std::string aj1T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/AFL_ipfRcpp/afl_inputs/" + std::to_string(t) + "_aj1T.qs";
  qs::c_qsave(aj1T,aj1T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aj1T values: "<< aj1T << std::endl;
  IntegerVector base(1);
  base[0]  = RcppDeepState_int();
  std::string base_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/AFL_ipfRcpp/afl_inputs/" + std::to_string(t) + "_base.qs";
  qs::c_qsave(base,base_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "base values: "<< base << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/AFL_ipfRcpp/afl_inputs/" + std::to_string(t) + "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfRcpp(aj1T,base[0],eps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
