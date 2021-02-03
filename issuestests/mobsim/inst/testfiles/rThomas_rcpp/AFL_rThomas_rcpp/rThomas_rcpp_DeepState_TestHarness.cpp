#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame rThomas_rcpp(int n_points, int n_mother_points, double sigma, double mu, double xmin, double xmax, double ymin, double ymax);

TEST(mobsim_deepstate_test,rThomas_rcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector n_points(1);
  n_points[0]  = RcppDeepState_int();
  std::string n_points_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_n_points.qs";
  qs::c_qsave(n_points,n_points_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_points values: "<< n_points << std::endl;
  IntegerVector n_mother_points(1);
  n_mother_points[0]  = RcppDeepState_int();
  std::string n_mother_points_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_n_mother_points.qs";
  qs::c_qsave(n_mother_points,n_mother_points_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_mother_points values: "<< n_mother_points << std::endl;
  NumericVector sigma(1);
  sigma[0]  = RcppDeepState_double();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  std::string mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_mu.qs";
  qs::c_qsave(mu,mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector xmin(1);
  xmin[0]  = RcppDeepState_double();
  std::string xmin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_xmin.qs";
  qs::c_qsave(xmin,xmin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmin values: "<< xmin << std::endl;
  NumericVector xmax(1);
  xmax[0]  = RcppDeepState_double();
  std::string xmax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_xmax.qs";
  qs::c_qsave(xmax,xmax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmax values: "<< xmax << std::endl;
  NumericVector ymin(1);
  ymin[0]  = RcppDeepState_double();
  std::string ymin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_ymin.qs";
  qs::c_qsave(ymin,ymin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ymin values: "<< ymin << std::endl;
  NumericVector ymax(1);
  ymax[0]  = RcppDeepState_double();
  std::string ymax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/AFL_rThomas_rcpp/afl_inputs/" + std::to_string(t) + "_ymax.qs";
  qs::c_qsave(ymax,ymax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ymax values: "<< ymax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rThomas_rcpp(n_points[0],n_mother_points[0],sigma[0],mu[0],xmin[0],xmax[0],ymin[0],ymax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
