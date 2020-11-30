#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double pt_boost(double q, double nu, double delta);

TEST(OwenQ_deepstate_test,pt_boost_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector q(1);
  q[0]  = RcppDeepState_double();
  qs::c_qsave(q,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/inputs/q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pt_boost(q[0],nu[0],delta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
