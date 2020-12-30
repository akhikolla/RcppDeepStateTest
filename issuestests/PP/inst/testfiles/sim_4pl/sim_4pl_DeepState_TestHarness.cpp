#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix sim_4pl(NumericVector beta, NumericVector alpha, NumericVector lowerA, NumericVector upperA, NumericVector theta);

TEST(PP_deepstate_test,sim_4pl_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector beta  = RcppDeepState_NumericVector();
  qs::c_qsave(beta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/inputs/beta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericVector alpha  = RcppDeepState_NumericVector();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector lowerA  = RcppDeepState_NumericVector();
  qs::c_qsave(lowerA,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/inputs/lowerA.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lowerA values: "<< lowerA << std::endl;
  NumericVector upperA  = RcppDeepState_NumericVector();
  qs::c_qsave(upperA,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/inputs/upperA.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "upperA values: "<< upperA << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sim_4pl(beta,alpha,lowerA,upperA,theta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
