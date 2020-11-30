#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ClustMeans(int nclust, IntegerVector start, NumericMatrix data);

TEST(lsbclust_deepstate_test,ClustMeans_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nclust(1);
  nclust[0]  = RcppDeepState_int();
  qs::c_qsave(nclust,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/inputs/nclust.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nclust values: "<< nclust << std::endl;
  IntegerVector start  = RcppDeepState_IntegerVector();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ClustMeans/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ClustMeans(nclust[0],start,data);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
