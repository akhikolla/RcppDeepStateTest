#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double poissonLogLkhd(double cz, double nz, double N, double C);

TEST(SpatialEpi_deepstate_test,poissonLogLkhd_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector cz(1);
  cz[0]  = RcppDeepState_double();
  std::string cz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/poissonLogLkhd/libFuzzer_poissonLogLkhd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cz.qs";
  qs::c_qsave(cz,cz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cz values: "<< cz << std::endl;
  NumericVector nz(1);
  nz[0]  = RcppDeepState_double();
  std::string nz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/poissonLogLkhd/libFuzzer_poissonLogLkhd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nz.qs";
  qs::c_qsave(nz,nz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  NumericVector N(1);
  N[0]  = RcppDeepState_double();
  std::string N_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/poissonLogLkhd/libFuzzer_poissonLogLkhd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N.qs";
  qs::c_qsave(N,N_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector C(1);
  C[0]  = RcppDeepState_double();
  std::string C_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/poissonLogLkhd/libFuzzer_poissonLogLkhd/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_C.qs";
  qs::c_qsave(C,C_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "C values: "<< C << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    poissonLogLkhd(cz[0],nz[0],N[0],C[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
