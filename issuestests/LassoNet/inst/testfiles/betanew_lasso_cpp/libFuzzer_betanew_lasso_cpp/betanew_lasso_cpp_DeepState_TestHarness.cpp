#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List betanew_lasso_cpp(NumericMatrix xx, NumericVector xy, NumericVector beta, NumericMatrix M, NumericVector y, double Lambda1, double Lambda2, double iter, double tol);

TEST(LassoNet_deepstate_test,betanew_lasso_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix xx  = RcppDeepState_NumericMatrix();
  std::string xx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xx.qs";
  qs::c_qsave(xx,xx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xx values: "<< xx << std::endl;
  NumericVector xy  = RcppDeepState_NumericVector();
  std::string xy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xy.qs";
  qs::c_qsave(xy,xy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xy values: "<< xy << std::endl;
  NumericVector beta  = RcppDeepState_NumericVector();
  std::string beta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_beta.qs";
  qs::c_qsave(beta,beta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  std::string M_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_M.qs";
  qs::c_qsave(M,M_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector Lambda1(1);
  Lambda1[0]  = RcppDeepState_double();
  std::string Lambda1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Lambda1.qs";
  qs::c_qsave(Lambda1,Lambda1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda1 values: "<< Lambda1 << std::endl;
  NumericVector Lambda2(1);
  Lambda2[0]  = RcppDeepState_double();
  std::string Lambda2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Lambda2.qs";
  qs::c_qsave(Lambda2,Lambda2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda2 values: "<< Lambda2 << std::endl;
  NumericVector iter(1);
  iter[0]  = RcppDeepState_double();
  std::string iter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_iter.qs";
  qs::c_qsave(iter,iter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iter values: "<< iter << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/LassoNet/inst/testfiles/betanew_lasso_cpp/libFuzzer_betanew_lasso_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    betanew_lasso_cpp(xx,xy,beta,M,y,Lambda1[0],Lambda2[0],iter[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
