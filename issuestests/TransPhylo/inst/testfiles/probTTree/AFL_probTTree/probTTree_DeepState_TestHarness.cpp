#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double probTTree(NumericMatrix ttree, double rOff, double pOff, double pi, double shGen, double scGen, double shSam, double scSam, double dateT, double delta_t);

TEST(TransPhylo_deepstate_test,probTTree_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix ttree  = RcppDeepState_NumericMatrix();
  std::string ttree_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_ttree.qs";
  qs::c_qsave(ttree,ttree_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ttree values: "<< ttree << std::endl;
  NumericVector rOff(1);
  rOff[0]  = RcppDeepState_double();
  std::string rOff_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_rOff.qs";
  qs::c_qsave(rOff,rOff_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rOff values: "<< rOff << std::endl;
  NumericVector pOff(1);
  pOff[0]  = RcppDeepState_double();
  std::string pOff_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_pOff.qs";
  qs::c_qsave(pOff,pOff_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pOff values: "<< pOff << std::endl;
  NumericVector pi(1);
  pi[0]  = RcppDeepState_double();
  std::string pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_pi.qs";
  qs::c_qsave(pi,pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector shGen(1);
  shGen[0]  = RcppDeepState_double();
  std::string shGen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_shGen.qs";
  qs::c_qsave(shGen,shGen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shGen values: "<< shGen << std::endl;
  NumericVector scGen(1);
  scGen[0]  = RcppDeepState_double();
  std::string scGen_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_scGen.qs";
  qs::c_qsave(scGen,scGen_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scGen values: "<< scGen << std::endl;
  NumericVector shSam(1);
  shSam[0]  = RcppDeepState_double();
  std::string shSam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_shSam.qs";
  qs::c_qsave(shSam,shSam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shSam values: "<< shSam << std::endl;
  NumericVector scSam(1);
  scSam[0]  = RcppDeepState_double();
  std::string scSam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_scSam.qs";
  qs::c_qsave(scSam,scSam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "scSam values: "<< scSam << std::endl;
  NumericVector dateT(1);
  dateT[0]  = RcppDeepState_double();
  std::string dateT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_dateT.qs";
  qs::c_qsave(dateT,dateT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dateT values: "<< dateT << std::endl;
  NumericVector delta_t(1);
  delta_t[0]  = RcppDeepState_double();
  std::string delta_t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/probTTree/AFL_probTTree/afl_inputs/" + std::to_string(t) + "_delta_t.qs";
  qs::c_qsave(delta_t,delta_t_t,
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
