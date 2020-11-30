#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::imat contingency_table(double precision, double rec, int length, double baserate);

TEST(rhoR_deepstate_test,contingency_table_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector precision(1);
  precision[0]  = RcppDeepState_double();
  qs::c_qsave(precision,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/inputs/precision.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "precision values: "<< precision << std::endl;
  NumericVector rec(1);
  rec[0]  = RcppDeepState_double();
  qs::c_qsave(rec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/inputs/rec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rec values: "<< rec << std::endl;
  IntegerVector length(1);
  length[0]  = RcppDeepState_int();
  qs::c_qsave(length,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/inputs/length.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "length values: "<< length << std::endl;
  NumericVector baserate(1);
  baserate[0]  = RcppDeepState_double();
  qs::c_qsave(baserate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/inputs/baserate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "baserate values: "<< baserate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    contingency_table(precision[0],rec[0],length[0],baserate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
