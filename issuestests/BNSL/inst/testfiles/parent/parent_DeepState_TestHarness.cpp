#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame parent(NumericMatrix df0, int h, int tw, int proc);

TEST(BNSL_deepstate_test,parent_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix df0  = RcppDeepState_NumericMatrix();
  qs::c_qsave(df0,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/inputs/df0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df0 values: "<< df0 << std::endl;
  IntegerVector h(1);
  h[0]  = RcppDeepState_int();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  IntegerVector tw(1);
  tw[0]  = RcppDeepState_int();
  qs::c_qsave(tw,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/inputs/tw.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tw values: "<< tw << std::endl;
  IntegerVector proc(1);
  proc[0]  = RcppDeepState_int();
  qs::c_qsave(proc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/parent/inputs/proc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proc values: "<< proc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    parent(df0,h[0],tw[0],proc[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
