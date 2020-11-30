#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector updateVecC(IntegerVector init_weight, IntegerVector add_index, IntegerVector remove_index, IntegerVector hhsize, IntegerVector hhid, int sizefactor);

TEST(simPop_deepstate_test,updateVecC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector init_weight  = RcppDeepState_IntegerVector();
  qs::c_qsave(init_weight,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/init_weight.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "init_weight values: "<< init_weight << std::endl;
  IntegerVector add_index  = RcppDeepState_IntegerVector();
  qs::c_qsave(add_index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/add_index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_index values: "<< add_index << std::endl;
  IntegerVector remove_index  = RcppDeepState_IntegerVector();
  qs::c_qsave(remove_index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/remove_index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_index values: "<< remove_index << std::endl;
  IntegerVector hhsize  = RcppDeepState_IntegerVector();
  qs::c_qsave(hhsize,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/hhsize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhsize values: "<< hhsize << std::endl;
  IntegerVector hhid  = RcppDeepState_IntegerVector();
  qs::c_qsave(hhid,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/hhid.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhid values: "<< hhid << std::endl;
  IntegerVector sizefactor(1);
  sizefactor[0]  = RcppDeepState_int();
  qs::c_qsave(sizefactor,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateVecC/inputs/sizefactor.qs",
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
