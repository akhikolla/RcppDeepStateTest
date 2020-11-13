#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double gc(int n, double a);

TEST(BNSL_deepstate_test,gc_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  std::ofstream n_stream;
  int n  = RcppDeepState_int();
  n_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/gc/inputs/n");
  n_stream << n;
  std::cout << "n values: "<< n << std::endl;
  n_stream.close();
  std::ofstream a_stream;
  double a  = RcppDeepState_double();
  a_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/gc/inputs/a");
  a_stream << a;
  std::cout << "a values: "<< a << std::endl;
  a_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    gc(n,a);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
