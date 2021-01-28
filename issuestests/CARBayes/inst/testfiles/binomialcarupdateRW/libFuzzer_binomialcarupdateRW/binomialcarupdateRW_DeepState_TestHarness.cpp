#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List binomialcarupdateRW(NumericMatrix Wtriplet, NumericMatrix Wbegfin, NumericVector Wtripletsum, const int nsites, NumericVector phi, double tau2, const NumericVector y, const NumericVector failures, const double phi_tune, double rho, NumericVector offset);

TEST(CARBayes_deepstate_test,binomialcarupdateRW_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wtriplet.qs";
  qs::c_qsave(Wtriplet,Wtriplet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  std::string Wbegfin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wbegfin.qs";
  qs::c_qsave(Wbegfin,Wbegfin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  NumericVector Wtripletsum  = RcppDeepState_NumericVector();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wtriplet.qs";
  std::string Wtripletsum_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wtripletsum.qs";
  qs::c_qsave(Wtripletsum,Wtripletsum_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtripletsum values: "<< Wtripletsum << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  std::string nsites_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nsites.qs";
  qs::c_qsave(nsites,nsites_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector tau2(1);
  tau2[0]  = RcppDeepState_double();
  std::string tau2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tau2.qs";
  qs::c_qsave(tau2,tau2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau2 values: "<< tau2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector failures  = RcppDeepState_NumericVector();
  std::string failures_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_failures.qs";
  qs::c_qsave(failures,failures_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "failures values: "<< failures << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  std::string phi_tune_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi_tune.qs";
  qs::c_qsave(phi_tune,phi_tune_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  std::string offset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialcarupdateRW/libFuzzer_binomialcarupdateRW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_offset.qs";
  qs::c_qsave(offset,offset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binomialcarupdateRW(Wtriplet,Wbegfin,Wtripletsum,nsites[0],phi,tau2[0],y,failures,phi_tune[0],rho[0],offset);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
