#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix updateSubmat(NumericMatrix submat, NumericMatrix sublb_red);
TEST(BacArena_deepstate_test,updateSubmat_test){
std::ofstream  submat_stream;
std::ofstream  sublb_red_stream;
 RInside();
 NumericMatrix submat = RcppDeepState_NumericMatrix ();
  submat_stream.open("/home/akhila/Documents/compileAttributescheck/BacArena/inst/testfiles/updateSubmat/inputs/ submat");
 submat_stream<< submat;
std::cout <<"submat values: "<< submat << std::endl;
 submat_stream.close();
 NumericMatrix sublb_red = RcppDeepState_NumericMatrix ();
  sublb_red_stream.open("/home/akhila/Documents/compileAttributescheck/BacArena/inst/testfiles/updateSubmat/inputs/ sublb_red");
 sublb_red_stream<< sublb_red;
std::cout <<"sublb_red values: "<< sublb_red << std::endl;
 sublb_red_stream.close();
 std::cout << "input ends" << std::endl;
 try{
updateSubmat( submat, sublb_red);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
