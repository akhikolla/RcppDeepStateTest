#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector updateVecC(IntegerVector init_weight, IntegerVector add_index, IntegerVector remove_index, IntegerVector hhsize, IntegerVector hhid, int sizefactor);

TEST(simPop_deepstate_test,updateVecC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector init_weight  = RcppDeepState_IntegerVector();
  std::string init_weight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_init_weight.qs";
  qs::c_qsave(init_weight,init_weight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "init_weight values: "<< init_weight << std::endl;
  IntegerVector add_index  = RcppDeepState_IntegerVector();
  std::string add_index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_add_index.qs";
  qs::c_qsave(add_index,add_index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_index values: "<< add_index << std::endl;
  IntegerVector remove_index  = RcppDeepState_IntegerVector();
  std::string remove_index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_remove_index.qs";
  qs::c_qsave(remove_index,remove_index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_index values: "<< remove_index << std::endl;
  IntegerVector hhsize  = RcppDeepState_IntegerVector();
  std::string hhsize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_hhsize.qs";
  qs::c_qsave(hhsize,hhsize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhsize values: "<< hhsize << std::endl;
  IntegerVector hhid  = RcppDeepState_IntegerVector();
  std::string hhid_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_hhid.qs";
  qs::c_qsave(hhid,hhid_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhid values: "<< hhid << std::endl;
  IntegerVector sizefactor(1);
  sizefactor[0]  = RcppDeepState_int();
  std::string sizefactor_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/AFL_updateVecC/afl_inputs/" + std::to_string(t) + "_sizefactor.qs";
  qs::c_qsave(sizefactor,sizefactor_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sizefactor values: "<< sizefactor << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    updateVecC(init_weight,add_index,remove_index,hhsize,hhid,sizefactor[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
