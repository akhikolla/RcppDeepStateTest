#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector p_updateTau(NumericMatrix Xm, NumericMatrix U1m, NumericMatrix U2m, NumericMatrix cov1m, NumericMatrix cov2m, NumericVector Rv, NumericVector Cv, NumericVector nu1v, NumericVector nu2v);

TEST(CMF_deepstate_test,p_updateTau_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/Xm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix U1m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(U1m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/U1m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U1m values: "<< U1m << std::endl;
  NumericMatrix U2m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(U2m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/U2m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U2m values: "<< U2m << std::endl;
  NumericMatrix cov1m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(cov1m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/cov1m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov1m values: "<< cov1m << std::endl;
  NumericMatrix cov2m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(cov2m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/cov2m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov2m values: "<< cov2m << std::endl;
  NumericVector Rv  = RcppDeepState_NumericVector();
  qs::c_qsave(Rv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/Rv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rv values: "<< Rv << std::endl;
  NumericVector Cv  = RcppDeepState_NumericVector();
  qs::c_qsave(Cv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/Cv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cv values: "<< Cv << std::endl;
  NumericVector nu1v  = RcppDeepState_NumericVector();
  qs::c_qsave(nu1v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/nu1v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu1v values: "<< nu1v << std::endl;
  NumericVector nu2v  = RcppDeepState_NumericVector();
  qs::c_qsave(nu2v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/inputs/nu2v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu2v values: "<< nu2v << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_updateTau(Xm,U1m,U2m,cov1m,cov2m,Rv,Cv,nu1v,nu2v);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
