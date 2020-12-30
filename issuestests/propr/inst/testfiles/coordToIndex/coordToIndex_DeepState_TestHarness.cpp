#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector coordToIndex(IntegerVector row, IntegerVector col, const int N);

TEST(propr_deepstate_test,coordToIndex_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector row  = RcppDeepState_IntegerVector();
  qs::c_qsave(row,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/inputs/row.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "row values: "<< row << std::endl;
  IntegerVector col  = RcppDeepState_IntegerVector();
  qs::c_qsave(col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/inputs/col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/coordToIndex/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    coordToIndex(row,col,N[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
