#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double cmi(NumericVector x, NumericVector y, NumericVector z, int proc);

TEST(BNSL_deepstate_test,cmi_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akolla/extdata/packages/BNSL/inst/testfiles/cmi/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akolla/extdata/packages/BNSL/inst/testfiles/cmi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akolla/extdata/packages/BNSL/inst/testfiles/cmi/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::ofstream proc_stream;
  int proc  = RcppDeepState_int();
  proc_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/cmi/inputs/proc");
  proc_stream << proc;
  std::cout << "proc values: "<< proc << std::endl;
  proc_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    cmi(x,y,z,proc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
