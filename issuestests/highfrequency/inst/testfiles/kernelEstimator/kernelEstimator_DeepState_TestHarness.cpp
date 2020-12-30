#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double kernelEstimator(NumericVector a, NumericVector b, int na, int q, int adj, NumericVector type, NumericVector ab, NumericVector ab2);

TEST(highfrequency_deepstate_test,kernelEstimator_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  qs::c_qsave(na,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/na.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector q(1);
  q[0]  = RcppDeepState_int();
  qs::c_qsave(q,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  IntegerVector adj(1);
  adj[0]  = RcppDeepState_int();
  qs::c_qsave(adj,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/adj.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "adj values: "<< adj << std::endl;
  NumericVector type  = RcppDeepState_NumericVector();
  qs::c_qsave(type,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector ab  = RcppDeepState_NumericVector();
  qs::c_qsave(ab,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/ab.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab values: "<< ab << std::endl;
  NumericVector ab2  = RcppDeepState_NumericVector();
  qs::c_qsave(ab2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/inputs/ab2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab2 values: "<< ab2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kernelEstimator(a,b,na[0],q[0],adj[0],type,ab,ab2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
