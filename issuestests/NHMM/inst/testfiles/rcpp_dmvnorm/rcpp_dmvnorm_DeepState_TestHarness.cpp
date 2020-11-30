#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rcpp_dmvnorm(Rcpp::NumericVector dataf, Rcpp::NumericVector meanf, Rcpp::NumericMatrix Siginvf, double detf);

TEST(NHMM_deepstate_test,rcpp_dmvnorm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector dataf  = RcppDeepState_NumericVector();
  qs::c_qsave(dataf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/inputs/dataf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dataf values: "<< dataf << std::endl;
  NumericVector meanf  = RcppDeepState_NumericVector();
  qs::c_qsave(meanf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/inputs/meanf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "meanf values: "<< meanf << std::endl;
  NumericMatrix Siginvf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Siginvf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/inputs/Siginvf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Siginvf values: "<< Siginvf << std::endl;
  NumericVector detf(1);
  detf[0]  = RcppDeepState_double();
  qs::c_qsave(detf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_dmvnorm/inputs/detf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "detf values: "<< detf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_dmvnorm(dataf,meanf,Siginvf,detf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
