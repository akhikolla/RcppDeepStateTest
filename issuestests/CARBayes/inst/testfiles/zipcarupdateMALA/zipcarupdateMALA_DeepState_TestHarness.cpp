#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List zipcarupdateMALA(NumericMatrix Wtriplet, NumericMatrix Wbegfin, NumericVector Wtripletsum, const int nsites, NumericVector phi, double tau2, const NumericVector y, const double phi_tune, double rho, NumericVector offset, NumericVector poiind);

TEST(CARBayes_deepstate_test,zipcarupdateMALA_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Wtriplet  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wtriplet,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/Wtriplet.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtriplet values: "<< Wtriplet << std::endl;
  NumericMatrix Wbegfin  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wbegfin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/Wbegfin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wbegfin values: "<< Wbegfin << std::endl;
  NumericVector Wtripletsum  = RcppDeepState_NumericVector();
  qs::c_qsave(Wtripletsum,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/Wtripletsum.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wtripletsum values: "<< Wtripletsum << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector tau2(1);
  tau2[0]  = RcppDeepState_double();
  qs::c_qsave(tau2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/tau2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau2 values: "<< tau2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector phi_tune(1);
  phi_tune[0]  = RcppDeepState_double();
  qs::c_qsave(phi_tune,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/phi_tune.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi_tune values: "<< phi_tune << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  NumericVector poiind  = RcppDeepState_NumericVector();
  qs::c_qsave(poiind,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/zipcarupdateMALA/inputs/poiind.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "poiind values: "<< poiind << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    zipcarupdateMALA(Wtriplet,Wbegfin,Wtripletsum,nsites[0],phi,tau2[0],y,phi_tune[0],rho[0],offset,poiind);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
