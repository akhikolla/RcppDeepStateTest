#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List rcpp_wt_bases_morlet(const NumericVector k, const double scale, const int param);
TEST(biwavelet_deepstate_test,rcpp_wt_bases_morlet_test){
std::ofstream  k_stream;
std::ofstream  scale_stream;
std::ofstream  param_stream;
RInside();
std::cout << "input starts" << std::endl;
  NumericVector k = RcppDeepState_NumericVector ();
  k_stream.open("/home/akhila/Documents/compileAttributescheck/biwavelet/inst/testfiles/rcpp_wt_bases_morlet/inputs/ k");
 k_stream<< k;
std::cout <<"k values: "<< k << std::endl;
 k_stream.close();
  double scale = RcppDeepState_double ();
  scale_stream.open("/home/akhila/Documents/compileAttributescheck/biwavelet/inst/testfiles/rcpp_wt_bases_morlet/inputs/ scale");
 scale_stream<< scale;
std::cout <<"scale values: "<< scale << std::endl;
 scale_stream.close();
  int param = RcppDeepState_int ();
  param_stream.open("/home/akhila/Documents/compileAttributescheck/biwavelet/inst/testfiles/rcpp_wt_bases_morlet/inputs/ param");
 param_stream<< param;
std::cout <<"param values: "<< param << std::endl;
 param_stream.close();
 std::cout << "input ends" << std::endl;
 try{
rcpp_wt_bases_morlet( k, scale, param);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
