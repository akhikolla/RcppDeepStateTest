#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int get_k_star(NumericVector x_star, int k_hat, int G_l, int G_r);

TEST(mosum_deepstate_test,get_k_star_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x_star  = RcppDeepState_NumericVector();
  qs::c_qsave(x_star,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/inputs/x_star.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_star values: "<< x_star << std::endl;
  IntegerVector k_hat(1);
  k_hat[0]  = RcppDeepState_int();
  qs::c_qsave(k_hat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/inputs/k_hat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k_hat values: "<< k_hat << std::endl;
  IntegerVector G_l(1);
  G_l[0]  = RcppDeepState_int();
  qs::c_qsave(G_l,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/inputs/G_l.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G_l values: "<< G_l << std::endl;
  IntegerVector G_r(1);
  G_r[0]  = RcppDeepState_int();
  qs::c_qsave(G_r,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/get_k_star/inputs/G_r.qs",
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
