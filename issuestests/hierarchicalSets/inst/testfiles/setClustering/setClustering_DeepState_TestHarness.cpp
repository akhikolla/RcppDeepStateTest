#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List setClustering(IntegerVector P, IntegerVector I, CharacterVector setNames, double threshold);

TEST(hierarchicalSets_deepstate_test,setClustering_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector P  = RcppDeepState_IntegerVector();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/inputs/P.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector I  = RcppDeepState_IntegerVector();
  qs::c_qsave(I,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/inputs/I.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  CharacterVector setNames  = RcppDeepState_CharacterVector();
  qs::c_qsave(setNames,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/inputs/setNames.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "setNames values: "<< setNames << std::endl;
  NumericVector threshold(1);
  threshold[0]  = RcppDeepState_double();
  qs::c_qsave(threshold,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/inputs/threshold.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "threshold values: "<< threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    setClustering(P,I,setNames,threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
