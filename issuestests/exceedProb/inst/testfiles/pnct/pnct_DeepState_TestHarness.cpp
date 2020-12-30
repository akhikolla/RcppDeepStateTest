#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double pnct(const double x, const double df, const double ncp);

TEST(exceedProb_deepstate_test,pnct_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  qs::c_qsave(df,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/inputs/df.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector ncp(1);
  ncp[0]  = RcppDeepState_double();
  qs::c_qsave(ncp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/inputs/ncp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncp values: "<< ncp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pnct(x[0],df[0],ncp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
