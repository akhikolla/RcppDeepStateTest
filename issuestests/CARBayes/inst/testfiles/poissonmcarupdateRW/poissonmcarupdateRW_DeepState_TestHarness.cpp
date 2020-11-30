#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List poissonmcarupdateRW(NumericMatrix Wtriplet, NumericMatrix Wbegfin, const int nsites, const int nvar, NumericMatrix phi, NumericMatrix Y, NumericMatrix phioffset, NumericVector denoffset, NumericMatrix Sigmainv, double rho, double phi_tune);

TEST(CARBayes_deepstate_test,poissonmcarupdateRW_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wtriplet,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/Wtriplet.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wbegfin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/Wbegfin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  IntegerVector nvar(1);
  nvar[0]  = RcppDeepState_int();
  qs::c_qsave(nvar,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/nvar.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nvar values: "<< nvar << std::endl;
  NumericMatrix phi  = RcppDeepState_NumericMatrix();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix phioffset  = RcppDeepState_NumericMatrix();
  qs::c_qsave(phioffset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/phioffset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phioffset values: "<< phioffset << std::endl;
  NumericVector denoffset  = RcppDeepState_NumericVector();
  qs::c_qsave(denoffset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/denoffset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denoffset values: "<< denoffset << std::endl;
  NumericMatrix Sigmainv  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Sigmainv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/Sigmainv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainv values: "<< Sigmainv << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  qs::c_qsave(phi_tune,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/poissonmcarupdateRW/inputs/phi_tune.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    poissonmcarupdateRW(Wtriplet,Wbegfin,nsites[0],nvar[0],phi,Y,phioffset,denoffset,Sigmainv,rho[0],phi_tune[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
