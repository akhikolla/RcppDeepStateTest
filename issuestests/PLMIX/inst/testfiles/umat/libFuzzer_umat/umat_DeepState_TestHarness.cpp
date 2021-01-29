#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix umat(NumericMatrix pi_inv);

TEST(PLMIX_deepstate_test,umat_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/umat/libFuzzer_umat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    umat(pi_inv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
