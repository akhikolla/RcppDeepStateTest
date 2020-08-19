#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix C_GP_cpp(NumericMatrix design, NumericVector response, NumericVector theta, NumericMatrix Ki, int ct);
TEST(activegp_deepstate_test,C_GP_cpp_test){
std::ofstream  design_stream;
std::ofstream  response_stream;
std::ofstream  theta_stream;
std::ofstream  Ki_stream;
std::ofstream  ct_stream;
 RInside();
 NumericMatrix design = RcppDeepState_NumericMatrix ();
  design_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/C_GP_cpp/inputs/ design");
 design_stream<< design;
std::cout <<"design values: "<< design << std::endl;
 design_stream.close();
 NumericVector response = RcppDeepState_NumericVector ();
  response_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/C_GP_cpp/inputs/ response");
 response_stream<< response;
std::cout <<"response values: "<< response << std::endl;
 response_stream.close();
 NumericVector theta = RcppDeepState_NumericVector ();
  theta_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/C_GP_cpp/inputs/ theta");
 theta_stream<< theta;
std::cout <<"theta values: "<< theta << std::endl;
 theta_stream.close();
 NumericMatrix Ki = RcppDeepState_NumericMatrix ();
  Ki_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/C_GP_cpp/inputs/ Ki");
 Ki_stream<< Ki;
std::cout <<"Ki values: "<< Ki << std::endl;
 Ki_stream.close();
 int ct = RcppDeepState_int ();
  ct_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/C_GP_cpp/inputs/ ct");
 ct_stream<< ct;
std::cout <<"ct values: "<< ct << std::endl;
 ct_stream.close();
 try{
C_GP_cpp( design, response, theta, Ki, ct);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
