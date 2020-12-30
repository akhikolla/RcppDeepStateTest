#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector iOwenQ2(double nu, double t, double delta, double R, int subdiv, double eps_abs, double eps_rel);

TEST(OwenQ_deepstate_test,iOwenQ2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  qs::c_qsave(t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector R(1);
  R[0]  = RcppDeepState_double();
  qs::c_qsave(R,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/R.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R values: "<< R << std::endl;
  IntegerVector subdiv(1);
  subdiv[0]  = RcppDeepState_int();
  qs::c_qsave(subdiv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/subdiv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subdiv values: "<< subdiv << std::endl;
  NumericVector eps_abs(1);
  eps_abs[0]  = RcppDeepState_double();
  qs::c_qsave(eps_abs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/eps_abs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_abs values: "<< eps_abs << std::endl;
  NumericVector eps_rel(1);
  eps_rel[0]  = RcppDeepState_double();
  qs::c_qsave(eps_rel,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/iOwenQ2/inputs/eps_rel.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps_rel values: "<< eps_rel << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    iOwenQ2(nu[0],t[0],delta[0],R[0],subdiv[0],eps_abs[0],eps_rel[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
