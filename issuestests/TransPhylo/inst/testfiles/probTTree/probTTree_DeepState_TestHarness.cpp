#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probTTree(NumericMatrix ttree, double rOff, double pOff, double pi, double shGen, double scGen, double shSam, double scSam, double dateT, double delta_t);

TEST(TransPhylo_deepstate_test,probTTree_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix ttree  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ttree,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/ttree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ttree values: "<< ttree << std::endl;
  NumericVector rOff(1);
  rOff[0]  = RcppDeepState_double();
  qs::c_qsave(rOff,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/rOff.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rOff values: "<< rOff << std::endl;
  NumericVector pOff(1);
  pOff[0]  = RcppDeepState_double();
  qs::c_qsave(pOff,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/pOff.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pOff values: "<< pOff << std::endl;
  NumericVector pi(1);
  pi[0]  = RcppDeepState_double();
  qs::c_qsave(pi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/pi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector shGen(1);
  shGen[0]  = RcppDeepState_double();
  qs::c_qsave(shGen,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/shGen.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shGen values: "<< shGen << std::endl;
  NumericVector scGen(1);
  scGen[0]  = RcppDeepState_double();
  qs::c_qsave(scGen,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/scGen.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scGen values: "<< scGen << std::endl;
  NumericVector shSam(1);
  shSam[0]  = RcppDeepState_double();
  qs::c_qsave(shSam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/shSam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shSam values: "<< shSam << std::endl;
  NumericVector scSam(1);
  scSam[0]  = RcppDeepState_double();
  qs::c_qsave(scSam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/scSam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scSam values: "<< scSam << std::endl;
  NumericVector dateT(1);
  dateT[0]  = RcppDeepState_double();
  qs::c_qsave(dateT,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/dateT.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dateT values: "<< dateT << std::endl;
  NumericVector delta_t(1);
  delta_t[0]  = RcppDeepState_double();
  qs::c_qsave(delta_t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/inputs/delta_t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta_t values: "<< delta_t << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    probTTree(ttree,rOff[0],pOff[0],pi[0],shGen[0],scGen[0],shSam[0],scSam[0],dateT[0],delta_t[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
