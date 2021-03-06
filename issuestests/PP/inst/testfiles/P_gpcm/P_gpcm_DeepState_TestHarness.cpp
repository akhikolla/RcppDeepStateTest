#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double P_gpcm(NumericVector delta, double alpha, double theta, int resp);

TEST(PP_deepstate_test,P_gpcm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  IntegerVector resp(1);
  resp[0]  = RcppDeepState_int();
  qs::c_qsave(resp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/inputs/resp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resp values: "<< resp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    P_gpcm(delta,alpha[0],theta[0],resp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
