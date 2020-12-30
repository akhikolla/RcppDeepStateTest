#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix random_steps_cpp_one_step(const int n_rand_steps, const double start_x, const double start_y, const double rel_angle, const NumericVector rand_sl, const NumericVector rand_ta);

TEST(amt_deepstate_test,random_steps_cpp_one_step_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector n_rand_steps(1);
  n_rand_steps[0]  = RcppDeepState_int();
  qs::c_qsave(n_rand_steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/n_rand_steps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rand_steps values: "<< n_rand_steps << std::endl;
  NumericVector start_x(1);
  start_x[0]  = RcppDeepState_double();
  qs::c_qsave(start_x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/start_x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start_x values: "<< start_x << std::endl;
  NumericVector start_y(1);
  start_y[0]  = RcppDeepState_double();
  qs::c_qsave(start_y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/start_y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start_y values: "<< start_y << std::endl;
  NumericVector rel_angle(1);
  rel_angle[0]  = RcppDeepState_double();
  qs::c_qsave(rel_angle,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/rel_angle.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rel_angle values: "<< rel_angle << std::endl;
  NumericVector rand_sl  = RcppDeepState_NumericVector();
  qs::c_qsave(rand_sl,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/rand_sl.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rand_sl values: "<< rand_sl << std::endl;
  NumericVector rand_ta  = RcppDeepState_NumericVector();
  qs::c_qsave(rand_ta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/random_steps_cpp_one_step/inputs/rand_ta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rand_ta values: "<< rand_ta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    random_steps_cpp_one_step(n_rand_steps[0],start_x[0],start_y[0],rel_angle[0],rand_sl,rand_ta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
