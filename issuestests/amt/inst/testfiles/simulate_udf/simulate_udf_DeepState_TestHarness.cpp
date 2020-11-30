#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector simulate_udf(int n_steps, int start, int nc, int nr, NumericMatrix mk, NumericMatrix hk);

TEST(amt_deepstate_test,simulate_udf_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n_steps(1);
  n_steps[0]  = RcppDeepState_int();
  qs::c_qsave(n_steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/n_steps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_steps values: "<< n_steps << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  IntegerVector nc(1);
  nc[0]  = RcppDeepState_int();
  qs::c_qsave(nc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/nc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nc values: "<< nc << std::endl;
  IntegerVector nr(1);
  nr[0]  = RcppDeepState_int();
  qs::c_qsave(nr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/nr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr values: "<< nr << std::endl;
  NumericMatrix mk  = RcppDeepState_NumericMatrix();
  qs::c_qsave(mk,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/mk.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mk values: "<< mk << std::endl;
  NumericMatrix hk  = RcppDeepState_NumericMatrix();
  qs::c_qsave(hk,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/simulate_udf/inputs/hk.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hk values: "<< hk << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    simulate_udf(n_steps[0],start[0],nc[0],nr[0],mk,hk);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
