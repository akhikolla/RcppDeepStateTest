#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector test_dims2columns(const NumericVector cpt, const CharacterVector class_var, const CharacterVector columns_db);
TEST(bnclassify_deepstate_test,test_dims2columns_test){
std::ofstream  cpt_stream;
std::ofstream  class_var_stream;
std::ofstream  columns_db_stream;
RInside();
std::cout << "input starts" << std::endl;
  NumericVector cpt = RcppDeepState_NumericVector ();
  cpt_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/test_dims2columns/inputs/ cpt");
 cpt_stream<< cpt;
std::cout <<"cpt values: "<< cpt << std::endl;
 cpt_stream.close();
  CharacterVector class_var = RcppDeepState_CharacterVector ();
  class_var_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/test_dims2columns/inputs/ class_var");
 class_var_stream<< class_var;
std::cout <<"class_var values: "<< class_var << std::endl;
 class_var_stream.close();
  CharacterVector columns_db = RcppDeepState_CharacterVector ();
  columns_db_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/test_dims2columns/inputs/ columns_db");
 columns_db_stream<< columns_db;
std::cout <<"columns_db values: "<< columns_db << std::endl;
 columns_db_stream.close();
 std::cout << "input ends" << std::endl;
 try{
test_dims2columns( cpt, class_var, columns_db);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
