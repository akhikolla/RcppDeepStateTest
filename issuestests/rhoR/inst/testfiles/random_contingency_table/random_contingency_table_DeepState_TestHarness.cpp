#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::imat random_contingency_table(int setLength, double baserate, double kappaMin, double kappaMax, double minPrecision, double maxPrecision);

TEST(rhoR_deepstate_test,random_contingency_table_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector setLength(1);
  setLength[0]  = RcppDeepState_int();
  qs::c_qsave(setLength,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/setLength.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "setLength values: "<< setLength << std::endl;
  NumericVector baserate(1);
  baserate[0]  = RcppDeepState_double();
  qs::c_qsave(baserate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/baserate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "baserate values: "<< baserate << std::endl;
  NumericVector kappaMin(1);
  kappaMin[0]  = RcppDeepState_double();
  qs::c_qsave(kappaMin,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/kappaMin.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappaMin values: "<< kappaMin << std::endl;
  NumericVector kappaMax(1);
  kappaMax[0]  = RcppDeepState_double();
  qs::c_qsave(kappaMax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/kappaMax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappaMax values: "<< kappaMax << std::endl;
  NumericVector minPrecision(1);
  minPrecision[0]  = RcppDeepState_double();
  qs::c_qsave(minPrecision,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/minPrecision.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "minPrecision values: "<< minPrecision << std::endl;
  NumericVector maxPrecision(1);
  maxPrecision[0]  = RcppDeepState_double();
  qs::c_qsave(maxPrecision,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/random_contingency_table/inputs/maxPrecision.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxPrecision values: "<< maxPrecision << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    random_contingency_table(setLength[0],baserate[0],kappaMin[0],kappaMax[0],minPrecision[0],maxPrecision[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
