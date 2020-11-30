#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List binomialindepupdateMALA(const int nsites, NumericVector theta, double sigma2, const NumericVector y, const NumericVector failures, const NumericVector trials, const double theta_tune, NumericVector offset);

TEST(CARBayes_deepstate_test,binomialindepupdateMALA_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nsites(1);
  nsites[0]  = RcppDeepState_int();
  qs::c_qsave(nsites,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/nsites.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsites values: "<< nsites << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector sigma2(1);
  sigma2[0]  = RcppDeepState_double();
  qs::c_qsave(sigma2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/sigma2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma2 values: "<< sigma2 << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector failures  = RcppDeepState_NumericVector();
  qs::c_qsave(failures,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/failures.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "failures values: "<< failures << std::endl;
  NumericVector trials  = RcppDeepState_NumericVector();
  qs::c_qsave(trials,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/trials.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trials values: "<< trials << std::endl;
  NumericVector theta_tune(1);
  theta_tune[0]  = RcppDeepState_double();
  qs::c_qsave(theta_tune,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/theta_tune.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta_tune values: "<< theta_tune << std::endl;
  NumericVector offset  = RcppDeepState_NumericVector();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CARBayes/inst/testfiles/binomialindepupdateMALA/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    binomialindepupdateMALA(nsites[0],theta,sigma2[0],y,failures,trials,theta_tune[0],offset);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
