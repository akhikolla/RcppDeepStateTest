#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double likelihood_dual(double est, double err, NumericVector numb_wells, NumericVector numb_cells, NumericVector numb_sample);

TEST(alphabetr_deepstate_test,likelihood_dual_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector est(1);
  est[0]  = RcppDeepState_double();
  qs::c_qsave(est,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dual/inputs/est.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "est values: "<< est << std::endl;
  NumericVector err(1);
  err[0]  = RcppDeepState_double();
  qs::c_qsave(err,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dual/inputs/err.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "err values: "<< err << std::endl;
  NumericVector numb_wells  = RcppDeepState_NumericVector();
  qs::c_qsave(numb_wells,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dual/inputs/numb_wells.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_wells values: "<< numb_wells << std::endl;
  NumericVector numb_cells  = RcppDeepState_NumericVector();
  qs::c_qsave(numb_cells,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dual/inputs/numb_cells.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_cells values: "<< numb_cells << std::endl;
  NumericVector numb_sample  = RcppDeepState_NumericVector();
  qs::c_qsave(numb_sample,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dual/inputs/numb_sample.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_sample values: "<< numb_sample << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    likelihood_dual(est[0],err[0],numb_wells,numb_cells,numb_sample);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
