#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gaussiancarmultilevelupdate(NumericMatrix Wtriplet, NumericMatrix Wbegfin, NumericVector Wtripletsum, NumericVector n_individual, const int nsites, NumericVector phi, double tau2, double rho, double nu2, NumericVector offset);

TEST(CARBayes_deepstate_test,gaussiancarmultilevelupdate_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wtriplet,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/Wtriplet.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wbegfin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/Wbegfin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  NumericVector Wtripletsum  = RcppDeepState_NumericVector();
  qs::c_qsave(Wtripletsum,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/Wtripletsum.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtripletsum values: "<< Wtripletsum << std::endl;
  NumericVector n_individual  = RcppDeepState_NumericVector();
  qs::c_qsave(n_individual,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/n_individual.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_individual values: "<< n_individual << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector tau2(1);
  tau2[0]  = RcppDeepState_double();
  qs::c_qsave(tau2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/tau2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau2 values: "<< tau2 << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector nu2(1);
  nu2[0]  = RcppDeepState_double();
  qs::c_qsave(nu2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/nu2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu2 values: "<< nu2 << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/gaussiancarmultilevelupdate/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gaussiancarmultilevelupdate(Wtriplet,Wbegfin,Wtripletsum,n_individual,nsites[0],phi,tau2[0],rho[0],nu2[0],offset);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
