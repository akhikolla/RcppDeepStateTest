#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ipfRcpp(NumericMatrix aj1T, int base, double eps);

TEST(equateMultiple_deepstate_test,ipfRcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix aj1T  = RcppDeepState_NumericMatrix();
  qs::c_qsave(aj1T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/inputs/aj1T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aj1T values: "<< aj1T << std::endl;
  IntegerVector base(1);
  base[0]  = RcppDeepState_int();
  qs::c_qsave(base,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/inputs/base.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "base values: "<< base << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  qs::c_qsave(eps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/ipfRcpp/inputs/eps.qs",
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
