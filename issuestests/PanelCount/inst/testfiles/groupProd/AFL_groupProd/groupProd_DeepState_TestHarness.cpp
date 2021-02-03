#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix groupProd(NumericVector v, NumericVector group);

TEST(PanelCount_deepstate_test,groupProd_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector v  = RcppDeepState_NumericVector();
  std::string v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/groupProd/AFL_groupProd/afl_inputs/" + std::to_string(t) + "_v.qs";
  qs::c_qsave(v,v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/groupProd/AFL_groupProd/afl_inputs/" + std::to_string(t) + "_group.qs";
  qs::c_qsave(group,group_t,
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
