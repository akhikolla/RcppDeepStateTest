#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector ipowen2(double nu, double t1, double t2, double delta1, double delta2, int subdiv, double eps_abs, double eps_rel);

TEST(OwenQ_deepstate_test,ipowen2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t1(1);
  t1[0]  = RcppDeepState_double();
  qs::c_qsave(t1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/t1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  NumericVector t2(1);
  t2[0]  = RcppDeepState_double();
  qs::c_qsave(t2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/t2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t2 values: "<< t2 << std::endl;
  NumericVector delta1(1);
  delta1[0]  = RcppDeepState_double();
  qs::c_qsave(delta1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/delta1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta1 values: "<< delta1 << std::endl;
  NumericVector delta2(1);
  delta2[0]  = RcppDeepState_double();
  qs::c_qsave(delta2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/delta2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta2 values: "<< delta2 << std::endl;
  IntegerVector subdiv(1);
  subdiv[0]  = RcppDeepState_int();
  qs::c_qsave(subdiv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/subdiv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subdiv values: "<< subdiv << std::endl;
  NumericVector eps_abs(1);
  eps_abs[0]  = RcppDeepState_double();
  qs::c_qsave(eps_abs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/eps_abs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_abs values: "<< eps_abs << std::endl;
  NumericVector eps_rel(1);
  eps_rel[0]  = RcppDeepState_double();
  qs::c_qsave(eps_rel,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/ipowen2/inputs/eps_rel.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_rel values: "<< eps_rel << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipowen2(nu[0],t1[0],t2[0],delta1[0],delta2[0],subdiv[0],eps_abs[0],eps_rel[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
