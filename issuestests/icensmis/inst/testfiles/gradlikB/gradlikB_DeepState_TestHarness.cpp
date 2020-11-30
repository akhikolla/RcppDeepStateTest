#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gradlikB(NumericVector parm, NumericMatrix Dm, NumericMatrix Xmat);

TEST(icensmis_deepstate_test,gradlikB_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  qs::c_qsave(parm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlikB/inputs/parm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlikB/inputs/Dm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xmat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlikB/inputs/Xmat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gradlikB(parm,Dm,Xmat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
