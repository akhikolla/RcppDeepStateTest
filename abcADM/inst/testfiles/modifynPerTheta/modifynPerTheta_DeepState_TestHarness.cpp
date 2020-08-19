#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void modifynPerTheta(const int newnPerTheta, const int verbose);
TEST(abcADM_deepstate_test,modifynPerTheta_test){
std::ofstream  newnPerTheta_stream;
std::ofstream  verbose_stream;
 RInside();
  int newnPerTheta = RcppDeepState_int ();
  newnPerTheta_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifynPerTheta/inputs/ newnPerTheta");
 newnPerTheta_stream<< newnPerTheta;
std::cout <<"newnPerTheta values: "<< newnPerTheta << std::endl;
 newnPerTheta_stream.close();
  int verbose = RcppDeepState_int ();
  verbose_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifynPerTheta/inputs/ verbose");
 verbose_stream<< verbose;
std::cout <<"verbose values: "<< verbose << std::endl;
 verbose_stream.close();
 try{
modifynPerTheta( newnPerTheta, verbose);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
