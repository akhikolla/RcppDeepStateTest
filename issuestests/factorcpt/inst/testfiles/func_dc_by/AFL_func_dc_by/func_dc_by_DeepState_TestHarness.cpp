#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List func_dc_by(NumericMatrix z, double dmby, double dtby);

TEST(factorcpt_deepstate_test,func_dc_by_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/AFL_func_dc_by/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector dmby(1);
  dmby[0]  = RcppDeepState_double();
  std::string dmby_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/AFL_func_dc_by/afl_inputs/" + std::to_string(t) + "_dmby.qs";
  qs::c_qsave(dmby,dmby_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dmby values: "<< dmby << std::endl;
  NumericVector dtby(1);
  dtby[0]  = RcppDeepState_double();
  std::string dtby_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/AFL_func_dc_by/afl_inputs/" + std::to_string(t) + "_dtby.qs";
  qs::c_qsave(dtby,dtby_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dtby values: "<< dtby << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    func_dc_by(z,dmby[0],dtby[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
