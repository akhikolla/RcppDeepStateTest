#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List poissonmcarupdateMALA(NumericMatrix Wtriplet, NumericMatrix Wbegfin, const int nsites, const int nvar, NumericMatrix phi, NumericMatrix Y, NumericMatrix phioffset, NumericVector denoffset, NumericMatrix Sigmainv, double rho, double phi_tune);

TEST(CARBayes_deepstate_test,poissonmcarupdateMALA_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  std::string Wtriplet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_Wtriplet.qs";
  qs::c_qsave(Wtriplet,Wtriplet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  std::string Wbegfin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_Wbegfin.qs";
  qs::c_qsave(Wbegfin,Wbegfin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  std::string nsites_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_nsites.qs";
  qs::c_qsave(nsites,nsites_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  IntegerVector nvar(1);
  nvar[0]  = RcppDeepState_int();
  std::string nvar_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_nvar.qs";
  qs::c_qsave(nvar,nvar_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nvar values: "<< nvar << std::endl;
  NumericMatrix phi  = RcppDeepState_NumericMatrix();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_phi.qs";
  qs::c_qsave(phi,phi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix phioffset  = RcppDeepState_NumericMatrix();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_phi.qs";
  std::string phioffset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_phioffset.qs";
  qs::c_qsave(phioffset,phioffset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phioffset values: "<< phioffset << std::endl;
  NumericVector denoffset  = RcppDeepState_NumericVector();
  std::string denoffset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_denoffset.qs";
  qs::c_qsave(denoffset,denoffset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denoffset values: "<< denoffset << std::endl;
  NumericMatrix Sigmainv  = RcppDeepState_NumericMatrix();
  std::string Sigmainv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_Sigmainv.qs";
  qs::c_qsave(Sigmainv,Sigmainv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainv values: "<< Sigmainv << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  std::string phi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_phi.qs";
  std::string phi_tune_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateMALA/AFL_poissonmcarupdateMALA/afl_inputs/" + std::to_string(t) + "_phi_tune.qs";
  qs::c_qsave(phi_tune,phi_tune_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    poissonmcarupdateMALA(Wtriplet,Wbegfin,nsites[0],nvar[0],phi,Y,phioffset,denoffset,Sigmainv,rho[0],phi_tune[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
