#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void modifyTimeStep(const double newdt, const int verbose);

TEST(abcADM_deepstate_test,modifyTimeStep_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector newdt(1);
  newdt[0]  = RcppDeepState_double();
  qs::c_qsave(newdt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifyTimeStep/inputs/newdt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newdt values: "<< newdt << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  qs::c_qsave(verbose,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifyTimeStep/inputs/verbose.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    modifyTimeStep(newdt[0],verbose[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
