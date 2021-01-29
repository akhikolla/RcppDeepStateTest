#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List OrderKmeansCpp(NumericMatrix x, int K, int num_init);

TEST(offlineChange_deepstate_test,OrderKmeansCpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/libFuzzer_OrderKmeansCpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/libFuzzer_OrderKmeansCpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector num_init(1);
  num_init[0]  = RcppDeepState_int();
  std::string num_init_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/libFuzzer_OrderKmeansCpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_num_init.qs";
  qs::c_qsave(num_init,num_init_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "num_init values: "<< num_init << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    OrderKmeansCpp(x,K[0],num_init[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
