#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ItemSimilSparseMat(NumericMatrix x, int dim, int DAMP);

TEST(rrecsys_deepstate_test,ItemSimilSparseMat_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector dim(1);
  dim[0]  = RcppDeepState_int();
  qs::c_qsave(dim,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/inputs/dim.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dim values: "<< dim << std::endl;
  IntegerVector DAMP(1);
  DAMP[0]  = RcppDeepState_int();
  qs::c_qsave(DAMP,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/inputs/DAMP.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DAMP values: "<< DAMP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ItemSimilSparseMat(x,dim[0],DAMP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
