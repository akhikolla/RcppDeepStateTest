#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector P_4pl4wle(NumericVector delta, double alpha, double theta, double la, double ua);

TEST(PP_deepstate_test,P_4pl4wle_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_4pl4wle/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_4pl4wle/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_4pl4wle/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector la(1);
  la[0]  = RcppDeepState_double();
  qs::c_qsave(la,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_4pl4wle/inputs/la.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "la values: "<< la << std::endl;
  NumericVector ua(1);
  ua[0]  = RcppDeepState_double();
  qs::c_qsave(ua,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_4pl4wle/inputs/ua.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ua values: "<< ua << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    P_4pl4wle(delta,alpha[0],theta[0],la[0],ua[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
