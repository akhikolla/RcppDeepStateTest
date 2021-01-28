#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List cond_var_gradient_hessian_cpp(NumericVector var, NumericVector eps, double omega, double alpha, double beta, NumericVector init_vals);

TEST(CPAT_deepstate_test,cond_var_gradient_hessian_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector var  = RcppDeepState_NumericVector();
  std::string var_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_var.qs";
  qs::c_qsave(var,var_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var values: "<< var << std::endl;
  NumericVector eps  = RcppDeepState_NumericVector();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  NumericVector omega(1);
  omega[0]  = RcppDeepState_double();
  std::string omega_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_omega.qs";
  qs::c_qsave(omega,omega_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omega values: "<< omega << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector beta(1);
  beta[0]  = RcppDeepState_double();
  std::string beta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_beta.qs";
  qs::c_qsave(beta,beta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericVector init_vals  = RcppDeepState_NumericVector();
  std::string init_vals_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/cond_var_gradient_hessian_cpp/libFuzzer_cond_var_gradient_hessian_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_init_vals.qs";
  qs::c_qsave(init_vals,init_vals_t,
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
