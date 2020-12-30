#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix powerdmat3(double phi1, double phi0, int J, double negpred);

TEST(icensmis_deepstate_test,powerdmat3_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector phi1(1);
  phi1[0]  = RcppDeepState_double();
  qs::c_qsave(phi1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/powerdmat3/inputs/phi1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi1 values: "<< phi1 << std::endl;
  NumericVector phi0(1);
  phi0[0]  = RcppDeepState_double();
  qs::c_qsave(phi0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/powerdmat3/inputs/phi0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi0 values: "<< phi0 << std::endl;
  IntegerVector J(1);
  J[0]  = RcppDeepState_int();
  qs::c_qsave(J,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/powerdmat3/inputs/J.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  NumericVector negpred(1);
  negpred[0]  = RcppDeepState_double();
  qs::c_qsave(negpred,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/powerdmat3/inputs/negpred.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "negpred values: "<< negpred << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    powerdmat3(phi1[0],phi0[0],J[0],negpred[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
