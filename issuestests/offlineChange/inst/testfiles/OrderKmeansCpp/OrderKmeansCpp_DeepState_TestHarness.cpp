#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List OrderKmeansCpp(NumericMatrix x, int K, int num_init);

TEST(offlineChange_deepstate_test,OrderKmeansCpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector num_init(1);
  num_init[0]  = RcppDeepState_int();
  qs::c_qsave(num_init,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/offlineChange/inst/testfiles/OrderKmeansCpp/inputs/num_init.qs",
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
