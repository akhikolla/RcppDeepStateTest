#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int interval_match(double proportion, NumericVector references);

TEST(AGread_deepstate_test,interval_match_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector proportion(1);
  proportion[0]  = RcppDeepState_double();
  qs::c_qsave(proportion,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interval_match/inputs/proportion.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proportion values: "<< proportion << std::endl;
  NumericVector references  = RcppDeepState_NumericVector();
  qs::c_qsave(references,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/AGread/inst/testfiles/interval_match/inputs/references.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "references values: "<< references << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    interval_match(proportion[0],references);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
