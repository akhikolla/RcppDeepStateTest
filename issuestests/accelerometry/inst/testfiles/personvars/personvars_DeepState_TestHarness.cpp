#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix personvars(NumericMatrix dayvars, int rows, int days, int wk, int we);

TEST(accelerometry_deepstate_test,personvars_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix dayvars  = RcppDeepState_NumericMatrix();
  qs::c_qsave(dayvars,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/inputs/dayvars.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dayvars values: "<< dayvars << std::endl;
  IntegerVector rows(1);
  rows[0]  = RcppDeepState_int();
  qs::c_qsave(rows,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/inputs/rows.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rows values: "<< rows << std::endl;
  IntegerVector days(1);
  days[0]  = RcppDeepState_int();
  qs::c_qsave(days,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/inputs/days.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "days values: "<< days << std::endl;
  IntegerVector wk(1);
  wk[0]  = RcppDeepState_int();
  qs::c_qsave(wk,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/inputs/wk.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wk values: "<< wk << std::endl;
  IntegerVector we(1);
  we[0]  = RcppDeepState_int();
  qs::c_qsave(we,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/personvars/inputs/we.qs",
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
