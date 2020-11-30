#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List poissonindepupdateMALA(const int nsites, NumericVector theta, double sigma2, const NumericVector y, const double theta_tune, NumericVector offset);

TEST(CARBayes_deepstate_test,poissonindepupdateMALA_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector sigma2(1);
  sigma2[0]  = RcppDeepState_double();
  qs::c_qsave(sigma2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/sigma2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma2 values: "<< sigma2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector theta_tune(1);
  theta_tune[0]  = RcppDeepState_double();
  qs::c_qsave(theta_tune,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/theta_tune.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta_tune values: "<< theta_tune << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    poissonindepupdateMALA(nsites[0],theta,sigma2[0],y,theta_tune[0],offset);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
