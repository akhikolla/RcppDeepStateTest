#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List integerise(NumericVector population);

TEST(humanleague_deepstate_test,integerise_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector population  = RcppDeepState_NumericVector();
  std::string population_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/humanleague/inst/testfiles/integerise/AFL_integerise/afl_inputs/" + std::to_string(t) + "_population.qs";
  qs::c_qsave(population,population_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "population values: "<< population << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    integerise(population);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
