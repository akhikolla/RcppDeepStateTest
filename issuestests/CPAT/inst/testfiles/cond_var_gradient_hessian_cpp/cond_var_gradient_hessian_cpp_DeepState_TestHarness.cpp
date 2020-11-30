#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List cond_var_gradient_hessian_cpp(NumericVector var, NumericVector eps, double omega, double alpha, double beta, NumericVector init_vals);

TEST(CPAT_deepstate_test,cond_var_gradient_hessian_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector var  = RcppDeepState_NumericVector();
  qs::c_qsave(var,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/var.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var values: "<< var << std::endl;
  NumericVector eps  = RcppDeepState_NumericVector();
  qs::c_qsave(eps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/eps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  NumericVector omega(1);
  omega[0]  = RcppDeepState_double();
  qs::c_qsave(omega,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/omega.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omega values: "<< omega << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector beta(1);
  beta[0]  = RcppDeepState_double();
  qs::c_qsave(beta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/beta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericVector init_vals  = RcppDeepState_NumericVector();
  qs::c_qsave(init_vals,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/inputs/init_vals.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "init_vals values: "<< init_vals << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cond_var_gradient_hessian_cpp(var,eps,omega[0],alpha[0],beta[0],init_vals);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
