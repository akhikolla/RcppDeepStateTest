#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double C_midrqLoss_bc(NumericVector b, NumericMatrix G, NumericMatrix x, NumericVector yo, NumericVector offset, int type, double tau, double lambda, int n, int p, int k);

TEST(Qtools_deepstate_test,C_midrqLoss_bc_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericMatrix G  = RcppDeepState_NumericMatrix();
  std::string G_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_G.qs";
  qs::c_qsave(G,G_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G values: "<< G << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector yo  = RcppDeepState_NumericVector();
  std::string yo_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_yo.qs";
  qs::c_qsave(yo,yo_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yo values: "<< yo << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  std::string offset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_offset.qs";
  qs::c_qsave(offset,offset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_type.qs";
  qs::c_qsave(type,type_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector tau(1);
  tau[0]  = RcppDeepState_double();
  std::string tau_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tau.qs";
  qs::c_qsave(tau,tau_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau values: "<< tau << std::endl;
  NumericVector lambda(1);
  lambda[0]  = RcppDeepState_double();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector p(1);
  p[0]  = RcppDeepState_int();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  std::string k_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_midrqLoss_bc/libFuzzer_C_midrqLoss_bc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_k.qs";
  qs::c_qsave(k,k_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    C_midrqLoss_bc(b,G,x,yo,offset,type[0],tau[0],lambda[0],n[0],p[0],k[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
