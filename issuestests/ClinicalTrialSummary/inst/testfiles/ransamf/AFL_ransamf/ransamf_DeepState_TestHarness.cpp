#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector ransamf(int repnum, int n, NumericVector B1inq, NumericVector xi1d, NumericVector xi2d, NumericVector cids1, NumericVector cids2);

TEST(ClinicalTrialSummary_deepstate_test,ransamf_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector repnum(1);
  repnum[0]  = RcppDeepState_int();
  std::string repnum_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_repnum.qs";
  qs::c_qsave(repnum,repnum_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "repnum values: "<< repnum << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector B1inq  = RcppDeepState_NumericVector();
  std::string B1inq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_B1inq.qs";
  qs::c_qsave(B1inq,B1inq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B1inq values: "<< B1inq << std::endl;
  NumericVector xi1d  = RcppDeepState_NumericVector();
  std::string xi1d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_xi1d.qs";
  qs::c_qsave(xi1d,xi1d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xi1d values: "<< xi1d << std::endl;
  NumericVector xi2d  = RcppDeepState_NumericVector();
  std::string xi2d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_xi2d.qs";
  qs::c_qsave(xi2d,xi2d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xi2d values: "<< xi2d << std::endl;
  NumericVector cids1  = RcppDeepState_NumericVector();
  std::string cids1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_cids1.qs";
  qs::c_qsave(cids1,cids1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cids1 values: "<< cids1 << std::endl;
  NumericVector cids2  = RcppDeepState_NumericVector();
  std::string cids2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ClinicalTrialSummary/inst/testfiles/ransamf/AFL_ransamf/afl_inputs/" + std::to_string(t) + "_cids2.qs";
  qs::c_qsave(cids2,cids2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cids2 values: "<< cids2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ransamf(repnum[0],n[0],B1inq,xi1d,xi2d,cids1,cids2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
