#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

/* step 1 */ NumericVector c_d_theta_sh_h_p(NumericMatrix y, NumericVector z, NumericVector l, double h);

TEST(cgAUC_deepstate_test,c_d_theta_sh_h_p_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_d_theta_sh_h_p/libFuzzer_c_d_theta_sh_h_p/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_d_theta_sh_h_p/libFuzzer_c_d_theta_sh_h_p/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector l  = RcppDeepState_NumericVector();
  std::string l_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_d_theta_sh_h_p/libFuzzer_c_d_theta_sh_h_p/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_l.qs";
  qs::c_qsave(l,l_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l values: "<< l << std::endl;
  NumericVector h(1);
  h[0]  = RcppDeepState_double();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_d_theta_sh_h_p/libFuzzer_c_d_theta_sh_h_p/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_d_theta_sh_h_p(y,z,l,h[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
