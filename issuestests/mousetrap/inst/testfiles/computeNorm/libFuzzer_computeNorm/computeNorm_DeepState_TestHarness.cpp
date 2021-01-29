#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

std::vector<double> computeNorm(double r);

TEST(mousetrap_deepstate_test,computeNorm_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  std::string r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/computeNorm/libFuzzer_computeNorm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_r.qs";
  qs::c_qsave(r,r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeNorm(r[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
