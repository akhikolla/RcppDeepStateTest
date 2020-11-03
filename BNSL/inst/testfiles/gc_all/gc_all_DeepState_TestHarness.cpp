#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double gc_all(IntegerVector cc, double a);

TEST(BNSL_deepstate_test,gc_all_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector cc  = RcppDeepState_IntegerVector();
  qs::c_qsave(cc,"/home/akolla/extdata/packages/BNSL/inst/testfiles/gc_all/inputs/cc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cc values: "<< cc << std::endl;
  std::ofstream a_stream;
  double a  = RcppDeepState_double();
  a_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/gc_all/inputs/a");
  a_stream << a;
  std::cout << "a values: "<< a << std::endl;
  a_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    gc_all(cc,a);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
