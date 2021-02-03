#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int get_k_star(NumericVector x_star, int k_hat, int G_l, int G_r);

TEST(mosum_deepstate_test,get_k_star_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x_star  = RcppDeepState_NumericVector();
  std::string x_star_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/AFL_get_k_star/afl_inputs/" + std::to_string(t) + "_x_star.qs";
  qs::c_qsave(x_star,x_star_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_star values: "<< x_star << std::endl;
  IntegerVector k_hat(1);
  k_hat[0]  = RcppDeepState_int();
  std::string k_hat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/AFL_get_k_star/afl_inputs/" + std::to_string(t) + "_k_hat.qs";
  qs::c_qsave(k_hat,k_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k_hat values: "<< k_hat << std::endl;
  IntegerVector G_l(1);
  G_l[0]  = RcppDeepState_int();
  std::string G_l_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/AFL_get_k_star/afl_inputs/" + std::to_string(t) + "_G_l.qs";
  qs::c_qsave(G_l,G_l_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G_l values: "<< G_l << std::endl;
  IntegerVector G_r(1);
  G_r[0]  = RcppDeepState_int();
  std::string G_r_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/AFL_get_k_star/afl_inputs/" + std::to_string(t) + "_G_r.qs";
  qs::c_qsave(G_r,G_r_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G_r values: "<< G_r << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_k_star(x_star,k_hat[0],G_l[0],G_r[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
