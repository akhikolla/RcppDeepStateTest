#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int rcpp_3d(int jf, int kf, int lf, int Jf, int Kf, int Lf);

TEST(NHMM_deepstate_test,rcpp_3d_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector jf(1);
  jf[0]  = RcppDeepState_int();
  qs::c_qsave(jf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/jf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jf values: "<< jf << std::endl;
  IntegerVector kf(1);
  kf[0]  = RcppDeepState_int();
  qs::c_qsave(kf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/kf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kf values: "<< kf << std::endl;
  IntegerVector lf(1);
  lf[0]  = RcppDeepState_int();
  qs::c_qsave(lf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/lf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lf values: "<< lf << std::endl;
  IntegerVector Jf(1);
  Jf[0]  = RcppDeepState_int();
  qs::c_qsave(Jf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/Jf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Jf values: "<< Jf << std::endl;
  IntegerVector Kf(1);
  Kf[0]  = RcppDeepState_int();
  qs::c_qsave(Kf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/Kf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Kf values: "<< Kf << std::endl;
  IntegerVector Lf(1);
  Lf[0]  = RcppDeepState_int();
  qs::c_qsave(Lf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_3d/inputs/Lf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Lf values: "<< Lf << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_3d(jf[0],kf[0],lf[0],Jf[0],Kf[0],Lf[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
