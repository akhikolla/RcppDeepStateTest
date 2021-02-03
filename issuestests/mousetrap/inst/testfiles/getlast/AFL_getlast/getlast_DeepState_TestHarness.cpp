#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector getlast(NumericMatrix trajectories);

TEST(mousetrap_deepstate_test,getlast_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix trajectories  = RcppDeepState_NumericMatrix();
  std::string trajectories_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/getlast/AFL_getlast/afl_inputs/" + std::to_string(t) + "_trajectories.qs";
  qs::c_qsave(trajectories,trajectories_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trajectories values: "<< trajectories << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getlast(trajectories);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
