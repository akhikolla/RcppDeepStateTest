#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix UpPhetpartial(NumericMatrix p, NumericMatrix ref_order, NumericMatrix pi_inv, NumericMatrix u_bin, NumericMatrix z_hat, NumericMatrix shape0, NumericVector rate0, IntegerVector n_rank);

TEST(PLMIX_deepstate_test,UpPhetpartial_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix ref_order  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ref_order,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/ref_order.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref_order values: "<< ref_order << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pi_inv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/pi_inv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericMatrix u_bin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(u_bin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/u_bin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u_bin values: "<< u_bin << std::endl;
  NumericMatrix z_hat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z_hat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/z_hat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z_hat values: "<< z_hat << std::endl;
  NumericMatrix shape0  = RcppDeepState_NumericMatrix();
  qs::c_qsave(shape0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/shape0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shape0 values: "<< shape0 << std::endl;
  NumericVector rate0  = RcppDeepState_NumericVector();
  qs::c_qsave(rate0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/rate0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate0 values: "<< rate0 << std::endl;
  IntegerVector n_rank  = RcppDeepState_IntegerVector();
  qs::c_qsave(n_rank,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/inputs/n_rank.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    UpPhetpartial(p,ref_order,pi_inv,u_bin,z_hat,shape0,rate0,n_rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
