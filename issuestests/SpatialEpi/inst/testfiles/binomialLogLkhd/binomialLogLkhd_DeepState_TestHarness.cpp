#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double binomialLogLkhd(double cz, double nz, double N, double C);

TEST(SpatialEpi_deepstate_test,binomialLogLkhd_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector cz(1);
  cz[0]  = RcppDeepState_double();
  qs::c_qsave(cz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/binomialLogLkhd/inputs/cz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cz values: "<< cz << std::endl;
  NumericVector nz(1);
  nz[0]  = RcppDeepState_double();
  qs::c_qsave(nz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/binomialLogLkhd/inputs/nz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  NumericVector N(1);
  N[0]  = RcppDeepState_double();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/binomialLogLkhd/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector C(1);
  C[0]  = RcppDeepState_double();
  qs::c_qsave(C,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/binomialLogLkhd/inputs/C.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "C values: "<< C << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binomialLogLkhd(cz[0],nz[0],N[0],C[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
