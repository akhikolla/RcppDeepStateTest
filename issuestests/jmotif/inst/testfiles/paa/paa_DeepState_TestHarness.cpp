#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector paa(NumericVector ts, int paa_num);

TEST(jmotif_deepstate_test,paa_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  qs::c_qsave(ts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/paa/inputs/ts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  IntegerVector paa_num(1);
  paa_num[0]  = RcppDeepState_int();
  qs::c_qsave(paa_num,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/paa/inputs/paa_num.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "paa_num values: "<< paa_num << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    paa(ts,paa_num[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
