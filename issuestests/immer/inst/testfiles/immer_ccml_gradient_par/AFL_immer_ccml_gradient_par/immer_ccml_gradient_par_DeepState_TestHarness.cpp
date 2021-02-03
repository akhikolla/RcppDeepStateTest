#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_ccml_gradient_par(Rcpp::NumericMatrix b_fixed, Rcpp::NumericVector A_, Rcpp::NumericVector par, Rcpp::NumericVector ll_index1, Rcpp::NumericVector item10, Rcpp::NumericVector item20, Rcpp::NumericVector cat1, Rcpp::NumericVector cat2, Rcpp::NumericVector n, Rcpp::NumericVector ntot, int max_ll_index);

TEST(immer_deepstate_test,immer_ccml_gradient_par_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix b_fixed  = RcppDeepState_NumericMatrix();
  std::string b_fixed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_b_fixed.qs";
  qs::c_qsave(b_fixed,b_fixed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b_fixed values: "<< b_fixed << std::endl;
  NumericVector A_  = RcppDeepState_NumericVector();
  std::string A__t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_A_.qs";
  qs::c_qsave(A_,A__t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A_ values: "<< A_ << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  std::string par_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_par.qs";
  qs::c_qsave(par,par_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  NumericVector ll_index1  = RcppDeepState_NumericVector();
  std::string ll_index1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_ll_index1.qs";
  qs::c_qsave(ll_index1,ll_index1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ll_index1 values: "<< ll_index1 << std::endl;
  NumericVector item10  = RcppDeepState_NumericVector();
  std::string item10_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_item10.qs";
  qs::c_qsave(item10,item10_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "item10 values: "<< item10 << std::endl;
  NumericVector item20  = RcppDeepState_NumericVector();
  std::string item20_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_item20.qs";
  qs::c_qsave(item20,item20_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "item20 values: "<< item20 << std::endl;
  NumericVector cat1  = RcppDeepState_NumericVector();
  std::string cat1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_cat1.qs";
  qs::c_qsave(cat1,cat1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cat1 values: "<< cat1 << std::endl;
  NumericVector cat2  = RcppDeepState_NumericVector();
  std::string cat2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_cat2.qs";
  qs::c_qsave(cat2,cat2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cat2 values: "<< cat2 << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ntot  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_n.qs";
  std::string ntot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_ntot.qs";
  qs::c_qsave(ntot,ntot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntot values: "<< ntot << std::endl;
  IntegerVector max_ll_index(1);
  max_ll_index[0]  = RcppDeepState_int();
  std::string max_ll_index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_ccml_gradient_par/AFL_immer_ccml_gradient_par/afl_inputs/" + std::to_string(t) + "_max_ll_index.qs";
  qs::c_qsave(max_ll_index,max_ll_index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_ll_index values: "<< max_ll_index << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_ccml_gradient_par(b_fixed,A_,par,ll_index1,item10,item20,cat1,cat2,n,ntot,max_ll_index[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
