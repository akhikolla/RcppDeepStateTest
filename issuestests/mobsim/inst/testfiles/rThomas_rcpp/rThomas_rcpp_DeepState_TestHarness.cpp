#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame rThomas_rcpp(int n_points, int n_mother_points, double sigma, double mu, double xmin, double xmax, double ymin, double ymax);

TEST(mobsim_deepstate_test,rThomas_rcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n_points(1);
  n_points[0]  = RcppDeepState_int();
  qs::c_qsave(n_points,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/n_points.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_points values: "<< n_points << std::endl;
  IntegerVector n_mother_points(1);
  n_mother_points[0]  = RcppDeepState_int();
  qs::c_qsave(n_mother_points,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/n_mother_points.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_mother_points values: "<< n_mother_points << std::endl;
  NumericVector sigma(1);
  sigma[0]  = RcppDeepState_double();
  qs::c_qsave(sigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/sigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  NumericVector mu(1);
  mu[0]  = RcppDeepState_double();
  qs::c_qsave(mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu values: "<< mu << std::endl;
  NumericVector xmin(1);
  xmin[0]  = RcppDeepState_double();
  qs::c_qsave(xmin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/xmin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmin values: "<< xmin << std::endl;
  NumericVector xmax(1);
  xmax[0]  = RcppDeepState_double();
  qs::c_qsave(xmax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/xmax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xmax values: "<< xmax << std::endl;
  NumericVector ymin(1);
  ymin[0]  = RcppDeepState_double();
  qs::c_qsave(ymin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/ymin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ymin values: "<< ymin << std::endl;
  NumericVector ymax(1);
  ymax[0]  = RcppDeepState_double();
  qs::c_qsave(ymax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/rThomas_rcpp/inputs/ymax.qs",
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
