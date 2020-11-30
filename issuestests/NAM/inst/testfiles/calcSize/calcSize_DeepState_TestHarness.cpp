#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int calcSize(NumericVector col, NumericVector fam);

TEST(NAM_deepstate_test,calcSize_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  qs::c_qsave(col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/calcSize/inputs/col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  NumericVector fam  = RcppDeepState_NumericVector();
  qs::c_qsave(fam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/calcSize/inputs/fam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    calcSize(col,fam);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
