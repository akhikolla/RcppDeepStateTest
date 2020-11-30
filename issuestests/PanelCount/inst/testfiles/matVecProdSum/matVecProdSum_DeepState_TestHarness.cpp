#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix matVecProdSum(NumericMatrix m, NumericVector ext, NumericVector v, NumericVector group);

TEST(PanelCount_deepstate_test,matVecProdSum_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSum/inputs/m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericVector ext  = RcppDeepState_NumericVector();
  qs::c_qsave(ext,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSum/inputs/ext.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ext values: "<< ext << std::endl;
  NumericVector v  = RcppDeepState_NumericVector();
  qs::c_qsave(v,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSum/inputs/v.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  NumericVector group  = RcppDeepState_NumericVector();
  qs::c_qsave(group,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelCount/inst/testfiles/matVecProdSum/inputs/group.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    matVecProdSum(m,ext,v,group);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
