#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector wbar(double tinf, double dateT, double rOff, double pOff, double pi, double shGen, double scGen, double shSam, double scSam, double delta_t);

TEST(TransPhylo_deepstate_test,wbar_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector tinf(1);
  tinf[0]  = RcppDeepState_double();
  qs::c_qsave(tinf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/tinf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tinf values: "<< tinf << std::endl;
  NumericVector dateT(1);
  dateT[0]  = RcppDeepState_double();
  qs::c_qsave(dateT,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/dateT.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dateT values: "<< dateT << std::endl;
  NumericVector rOff(1);
  rOff[0]  = RcppDeepState_double();
  qs::c_qsave(rOff,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/rOff.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rOff values: "<< rOff << std::endl;
  NumericVector pOff(1);
  pOff[0]  = RcppDeepState_double();
  qs::c_qsave(pOff,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/pOff.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pOff values: "<< pOff << std::endl;
  NumericVector pi(1);
  pi[0]  = RcppDeepState_double();
  qs::c_qsave(pi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/pi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector shGen(1);
  shGen[0]  = RcppDeepState_double();
  qs::c_qsave(shGen,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/shGen.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shGen values: "<< shGen << std::endl;
  NumericVector scGen(1);
  scGen[0]  = RcppDeepState_double();
  qs::c_qsave(scGen,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/scGen.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scGen values: "<< scGen << std::endl;
  NumericVector shSam(1);
  shSam[0]  = RcppDeepState_double();
  qs::c_qsave(shSam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/shSam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shSam values: "<< shSam << std::endl;
  NumericVector scSam(1);
  scSam[0]  = RcppDeepState_double();
  qs::c_qsave(scSam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/scSam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scSam values: "<< scSam << std::endl;
  NumericVector delta_t(1);
  delta_t[0]  = RcppDeepState_double();
  qs::c_qsave(delta_t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/wbar/inputs/delta_t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta_t values: "<< delta_t << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    wbar(tinf[0],dateT[0],rOff[0],pOff[0],pi[0],shGen[0],scGen[0],shSam[0],scSam[0],delta_t[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
