#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool hasPolytomy(Rcpp::IntegerVector ances);

TEST(phylobase_deepstate_test,hasPolytomy_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector ances  = RcppDeepState_IntegerVector();
  qs::c_qsave(ances,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/hasPolytomy/inputs/ances.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ances values: "<< ances << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hasPolytomy(ances);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
