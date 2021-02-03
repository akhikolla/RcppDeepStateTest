#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix personvars(NumericMatrix dayvars, int rows, int days, int wk, int we);

TEST(accelerometry_deepstate_test,personvars_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix dayvars  = RcppDeepState_NumericMatrix();
  std::string dayvars_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/AFL_personvars/afl_inputs/" + std::to_string(t) + "_dayvars.qs";
  qs::c_qsave(dayvars,dayvars_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dayvars values: "<< dayvars << std::endl;
  IntegerVector rows(1);
  rows[0]  = RcppDeepState_int();
  std::string rows_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/AFL_personvars/afl_inputs/" + std::to_string(t) + "_rows.qs";
  qs::c_qsave(rows,rows_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rows values: "<< rows << std::endl;
  IntegerVector days(1);
  days[0]  = RcppDeepState_int();
  std::string days_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/AFL_personvars/afl_inputs/" + std::to_string(t) + "_days.qs";
  qs::c_qsave(days,days_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "days values: "<< days << std::endl;
  IntegerVector wk(1);
  wk[0]  = RcppDeepState_int();
  std::string wk_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/AFL_personvars/afl_inputs/" + std::to_string(t) + "_wk.qs";
  qs::c_qsave(wk,wk_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wk values: "<< wk << std::endl;
  IntegerVector we(1);
  we[0]  = RcppDeepState_int();
  std::string we_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/AFL_personvars/afl_inputs/" + std::to_string(t) + "_we.qs";
  qs::c_qsave(we,we_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "we values: "<< we << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    personvars(dayvars,rows[0],days[0],wk[0],we[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
