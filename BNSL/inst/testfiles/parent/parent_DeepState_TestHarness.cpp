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
  qs::c_qsave(df0,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/parent/inputs/df0.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df0 values: "<< df0 << std::endl;
  std::ofstream h_stream;
  int h  = RcppDeepState_int();
  h_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/parent/inputs/h");
  h_stream << h;
  std::cout << "h values: "<< h << std::endl;
  h_stream.close();
  std::ofstream tw_stream;
  int tw  = RcppDeepState_int();
  tw_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/parent/inputs/tw");
  tw_stream << tw;
  std::cout << "tw values: "<< tw << std::endl;
  tw_stream.close();
  std::ofstream proc_stream;
  int proc  = RcppDeepState_int();
  proc_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/parent/inputs/proc");
  proc_stream << proc;
  std::cout << "proc values: "<< proc << std::endl;
  proc_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    parent(df0,h,tw,proc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
