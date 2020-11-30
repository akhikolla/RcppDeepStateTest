#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector funX(NumericVector col, int finsiz);

TEST(NAM_deepstate_test,funX_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  qs::c_qsave(col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funX/inputs/col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector finsiz(1);
  finsiz[0]  = RcppDeepState_int();
  qs::c_qsave(finsiz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funX/inputs/finsiz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "finsiz values: "<< finsiz << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    funX(col,finsiz[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
