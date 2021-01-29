#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix matVecProdSumExt(NumericMatrix m, NumericVector ext, NumericVector ext2, NumericVector v, NumericVector group);

TEST(PanelCount_deepstate_test,matVecProdSumExt_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix m  = RcppDeepState_NumericMatrix();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m.qs";
  qs::c_qsave(m,m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericVector ext  = RcppDeepState_NumericVector();
  std::string ext_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ext.qs";
  qs::c_qsave(ext,ext_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ext values: "<< ext << std::endl;
  NumericVector ext2  = RcppDeepState_NumericVector();
  std::string ext_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ext.qs";
  std::string ext2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ext2.qs";
  qs::c_qsave(ext2,ext2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ext2 values: "<< ext2 << std::endl;
  NumericVector v  = RcppDeepState_NumericVector();
  std::string v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_v.qs";
  qs::c_qsave(v,v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSumExt/libFuzzer_matVecProdSumExt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_group.qs";
  qs::c_qsave(group,group_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    matVecProdSumExt(m,ext,ext2,v,group);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
