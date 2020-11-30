#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix Estep(NumericMatrix p, NumericMatrix ref_order, NumericVector weights, NumericMatrix pi_inv);

TEST(PLMIX_deepstate_test,Estep_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/Estep/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix ref_order  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ref_order,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/Estep/inputs/ref_order.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref_order values: "<< ref_order << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  qs::c_qsave(weights,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/Estep/inputs/weights.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pi_inv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/Estep/inputs/pi_inv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Estep(p,ref_order,weights,pi_inv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
