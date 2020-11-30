#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List rolling_groups(IntegerVector values, int n);

TEST(PAutilities_deepstate_test,rolling_groups_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector values  = RcppDeepState_IntegerVector();
  qs::c_qsave(values,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/rolling_groups/inputs/values.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "values values: "<< values << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PAutilities/inst/testfiles/rolling_groups/inputs/n.qs",
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
