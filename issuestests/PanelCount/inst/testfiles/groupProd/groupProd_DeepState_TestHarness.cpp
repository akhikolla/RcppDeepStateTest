#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix groupProd(NumericVector v, NumericVector group);

TEST(PanelCount_deepstate_test,groupProd_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector v  = RcppDeepState_NumericVector();
  qs::c_qsave(v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/groupProd/inputs/v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  qs::c_qsave(group,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/groupProd/inputs/group.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    groupProd(v,group);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
