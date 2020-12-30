#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List binomialmcarupdateRW(NumericMatrix Wtriplet, NumericMatrix Wbegfin, const int nsites, const int nvar, NumericMatrix phi, NumericMatrix Y, NumericMatrix failures, NumericMatrix phioffset, NumericVector denoffset, NumericMatrix Sigmainv, double rho, double phi_tune);

TEST(CARBayes_deepstate_test,binomialmcarupdateRW_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wtriplet,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/Wtriplet.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wbegfin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/Wbegfin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  IntegerVector nvar(1);
  nvar[0]  = RcppDeepState_int();
  qs::c_qsave(nvar,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/nvar.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nvar values: "<< nvar << std::endl;
  NumericMatrix phi  = RcppDeepState_NumericMatrix();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix failures  = RcppDeepState_NumericMatrix();
  qs::c_qsave(failures,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/failures.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "failures values: "<< failures << std::endl;
  NumericMatrix phioffset  = RcppDeepState_NumericMatrix();
  qs::c_qsave(phioffset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/phioffset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phioffset values: "<< phioffset << std::endl;
  NumericVector denoffset  = RcppDeepState_NumericVector();
  qs::c_qsave(denoffset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/denoffset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "denoffset values: "<< denoffset << std::endl;
  NumericMatrix Sigmainv  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Sigmainv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/Sigmainv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigmainv values: "<< Sigmainv << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  qs::c_qsave(phi_tune,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialmcarupdateRW/inputs/phi_tune.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binomialmcarupdateRW(Wtriplet,Wbegfin,nsites[0],nvar[0],phi,Y,failures,phioffset,denoffset,Sigmainv,rho[0],phi_tune[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
