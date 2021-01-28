#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List gaussianmcarupdateMALA(NumericMatrix Wtriplet, NumericMatrix Wbegfin, const int nsites, const int nvar, NumericMatrix phi, NumericMatrix phioffset, NumericVector denoffset, NumericMatrix Sigmainv, double rho, NumericVector nu2, double phi_tune);

TEST(CARBayes_deepstate_test,gaussianmcarupdateMALA_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wtriplet.qs";
  qs::c_qsave(Wtriplet,Wtriplet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  std::string Wbegfin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Wbegfin.qs";
  qs::c_qsave(Wbegfin,Wbegfin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  std::string nsites_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nsites.qs";
  qs::c_qsave(nsites,nsites_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  IntegerVector nvar(1);
  nvar[0]  = RcppDeepState_int();
  std::string nvar_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nvar.qs";
  qs::c_qsave(nvar,nvar_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nvar values: "<< nvar << std::endl;
  NumericMatrix phi  = RcppDeepState_NumericMatrix();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericMatrix phioffset  = RcppDeepState_NumericMatrix();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  std::string phioffset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phioffset.qs";
  qs::c_qsave(phioffset,phioffset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phioffset values: "<< phioffset << std::endl;
  NumericVector denoffset  = RcppDeepState_NumericVector();
  std::string denoffset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_denoffset.qs";
  qs::c_qsave(denoffset,denoffset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denoffset values: "<< denoffset << std::endl;
  NumericMatrix Sigmainv  = RcppDeepState_NumericMatrix();
  std::string Sigmainv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Sigmainv.qs";
  qs::c_qsave(Sigmainv,Sigmainv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainv values: "<< Sigmainv << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector nu2  = RcppDeepState_NumericVector();
  std::string nu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nu2.qs";
  qs::c_qsave(nu2,nu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu2 values: "<< nu2 << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi.qs";
  std::string phi_tune_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussianmcarupdateMALA/libFuzzer_gaussianmcarupdateMALA/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi_tune.qs";
  qs::c_qsave(phi_tune,phi_tune_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gaussianmcarupdateMALA(Wtriplet,Wbegfin,nsites[0],nvar[0],phi,phioffset,denoffset,Sigmainv,rho[0],nu2,phi_tune[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
