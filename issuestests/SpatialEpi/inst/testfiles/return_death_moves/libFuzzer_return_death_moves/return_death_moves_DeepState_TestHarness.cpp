#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix return_death_moves(NumericVector theta);

TEST(SpatialEpi_deepstate_test,return_death_moves_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/return_death_moves/libFuzzer_return_death_moves/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    return_death_moves(theta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
