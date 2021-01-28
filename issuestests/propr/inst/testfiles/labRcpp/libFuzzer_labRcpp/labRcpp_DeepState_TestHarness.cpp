#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List labRcpp(int nfeats);

TEST(propr_deepstate_test,labRcpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nfeats(1);
  nfeats[0]  = RcppDeepState_int();
  std::string nfeats_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/propr/inst/testfiles/labRcpp/libFuzzer_labRcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nfeats.qs";
  qs::c_qsave(nfeats,nfeats_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nfeats values: "<< nfeats << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    labRcpp(nfeats[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
