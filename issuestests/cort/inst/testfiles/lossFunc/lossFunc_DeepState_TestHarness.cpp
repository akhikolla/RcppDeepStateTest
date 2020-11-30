#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double lossFunc(const NumericVector bp, const NumericMatrix bin_repr, const NumericMatrix z);

TEST(cort_deepstate_test,lossFunc_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector bp  = RcppDeepState_NumericVector();
  qs::c_qsave(bp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/inputs/bp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bp values: "<< bp << std::endl;
  NumericMatrix bin_repr  = RcppDeepState_NumericMatrix();
  qs::c_qsave(bin_repr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/inputs/bin_repr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bin_repr values: "<< bin_repr << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/lossFunc/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lossFunc(bp,bin_repr,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
