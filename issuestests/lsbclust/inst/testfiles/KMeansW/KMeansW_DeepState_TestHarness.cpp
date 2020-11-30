#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List KMeansW(int nclust, IntegerVector start, NumericMatrix data, NumericVector weight, double eps, int IterMax);

TEST(lsbclust_deepstate_test,KMeansW_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nclust(1);
  nclust[0]  = RcppDeepState_int();
  qs::c_qsave(nclust,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/nclust.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nclust values: "<< nclust << std::endl;
  IntegerVector start  = RcppDeepState_IntegerVector();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector weight  = RcppDeepState_NumericVector();
  qs::c_qsave(weight,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/weight.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weight values: "<< weight << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  qs::c_qsave(eps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/eps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  IntegerVector IterMax(1);
  IterMax[0]  = RcppDeepState_int();
  qs::c_qsave(IterMax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/inputs/IterMax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "IterMax values: "<< IterMax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    KMeansW(nclust[0],start,data,weight,eps[0],IterMax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
