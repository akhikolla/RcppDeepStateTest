#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix CompProbZpartial(NumericMatrix p, NumericMatrix pi_inv, NumericMatrix Y, NumericMatrix u_bin, IntegerVector n_rank, NumericVector omega);

TEST(PLMIX_deepstate_test,CompProbZpartial_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pi_inv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/pi_inv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix u_bin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(u_bin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/u_bin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u_bin values: "<< u_bin << std::endl;
  IntegerVector n_rank  = RcppDeepState_IntegerVector();
  qs::c_qsave(n_rank,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/n_rank.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  NumericVector omega  = RcppDeepState_NumericVector();
  qs::c_qsave(omega,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/inputs/omega.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omega values: "<< omega << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CompProbZpartial(p,pi_inv,Y,u_bin,n_rank,omega);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
