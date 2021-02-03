#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List ChanVese(Rcpp::NumericMatrix im, double Mu, double Nu, double Lambda1, double Lambda2, double tol, int maxiter, double dt, Rcpp::NumericMatrix phi);

TEST(imagerExtra_deepstate_test,ChanVese_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix im  = RcppDeepState_NumericMatrix();
  std::string im_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_im.qs";
  qs::c_qsave(im,im_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "im values: "<< im << std::endl;
  NumericVector Mu(1);
  Mu[0]  = RcppDeepState_double();
  std::string Mu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_Mu.qs";
  qs::c_qsave(Mu,Mu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu values: "<< Mu << std::endl;
  NumericVector Nu(1);
  Nu[0]  = RcppDeepState_double();
  std::string Nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_Nu.qs";
  qs::c_qsave(Nu,Nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Nu values: "<< Nu << std::endl;
  NumericVector Lambda1(1);
  Lambda1[0]  = RcppDeepState_double();
  std::string Lambda1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_Lambda1.qs";
  qs::c_qsave(Lambda1,Lambda1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda1 values: "<< Lambda1 << std::endl;
  NumericVector Lambda2(1);
  Lambda2[0]  = RcppDeepState_double();
  std::string Lambda2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_Lambda2.qs";
  qs::c_qsave(Lambda2,Lambda2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lambda2 values: "<< Lambda2 << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  IntegerVector maxiter(1);
  maxiter[0]  = RcppDeepState_int();
  std::string maxiter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_maxiter.qs";
  qs::c_qsave(maxiter,maxiter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxiter values: "<< maxiter << std::endl;
  NumericVector dt(1);
  dt[0]  = RcppDeepState_double();
  std::string dt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_dt.qs";
  qs::c_qsave(dt,dt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dt values: "<< dt << std::endl;
  NumericMatrix phi  = RcppDeepState_NumericMatrix();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/imagerExtra/inst/testfiles/ChanVese/AFL_ChanVese/afl_inputs/" + std::to_string(t) + "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ChanVese(im,Mu[0],Nu[0],Lambda1[0],Lambda2[0],tol[0],maxiter[0],dt[0],phi);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
