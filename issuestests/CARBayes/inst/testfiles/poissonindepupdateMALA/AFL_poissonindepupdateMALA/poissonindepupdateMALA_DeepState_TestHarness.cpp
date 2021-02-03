#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List poissonindepupdateMALA(const int nsites, NumericVector theta, double sigma2, const NumericVector y, const double theta_tune, NumericVector offset);

TEST(CARBayes_deepstate_test,poissonindepupdateMALA_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  std::string nsites_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_nsites.qs";
  qs::c_qsave(nsites,nsites_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector sigma2(1);
  sigma2[0]  = RcppDeepState_double();
  std::string sigma2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_sigma2.qs";
  qs::c_qsave(sigma2,sigma2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma2 values: "<< sigma2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector theta_tune(1);
  theta_tune[0]  = RcppDeepState_double();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_theta.qs";
  std::string theta_tune_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_theta_tune.qs";
  qs::c_qsave(theta_tune,theta_tune_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta_tune values: "<< theta_tune << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  std::string offset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonindepupdateMALA/AFL_poissonindepupdateMALA/afl_inputs/" + std::to_string(t) + "_offset.qs";
  qs::c_qsave(offset,offset_t,
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
