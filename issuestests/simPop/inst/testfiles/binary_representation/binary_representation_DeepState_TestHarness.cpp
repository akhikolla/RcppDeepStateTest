#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix binary_representation(IntegerVector levels, IntegerVector values);

TEST(simPop_deepstate_test,binary_representation_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector levels  = RcppDeepState_IntegerVector();
  qs::c_qsave(levels,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/binary_representation/inputs/levels.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "levels values: "<< levels << std::endl;
  IntegerVector values  = RcppDeepState_IntegerVector();
  qs::c_qsave(values,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/binary_representation/inputs/values.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "values values: "<< values << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binary_representation(levels,values);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
