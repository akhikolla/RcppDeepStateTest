#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix dmat(NumericVector id, NumericVector time, IntegerVector result, double phi1, double phi0, double negpred);

TEST(icensmis_deepstate_test,dmat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector id  = RcppDeepState_NumericVector();
  qs::c_qsave(id,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/id.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  NumericVector time  = RcppDeepState_NumericVector();
  qs::c_qsave(time,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/time.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time values: "<< time << std::endl;
  IntegerVector result  = RcppDeepState_IntegerVector();
  qs::c_qsave(result,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/result.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "result values: "<< result << std::endl;
  NumericVector phi1(1);
  phi1[0]  = RcppDeepState_double();
  qs::c_qsave(phi1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/phi1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi1 values: "<< phi1 << std::endl;
  NumericVector phi0(1);
  phi0[0]  = RcppDeepState_double();
  qs::c_qsave(phi0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/phi0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi0 values: "<< phi0 << std::endl;
  NumericVector negpred(1);
  negpred[0]  = RcppDeepState_double();
  qs::c_qsave(negpred,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/dmat/inputs/negpred.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "negpred values: "<< negpred << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dmat(id,time,result,phi1[0],phi0[0],negpred[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
