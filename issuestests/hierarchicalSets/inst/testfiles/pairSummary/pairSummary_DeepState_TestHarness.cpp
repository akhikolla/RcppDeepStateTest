#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame pairSummary(IntegerVector P, IntegerVector I, IntegerVector order);

TEST(hierarchicalSets_deepstate_test,pairSummary_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector P  = RcppDeepState_IntegerVector();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector I  = RcppDeepState_IntegerVector();
  qs::c_qsave(I,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/inputs/I.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  IntegerVector order  = RcppDeepState_IntegerVector();
  qs::c_qsave(order,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/inputs/order.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "order values: "<< order << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pairSummary(P,I,order);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
