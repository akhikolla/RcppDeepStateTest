#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix SPM(NumericVector blk, NumericVector row, NumericVector col, double rN, double cN);

TEST(NAM_deepstate_test,SPM_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector blk  = RcppDeepState_NumericVector();
  qs::c_qsave(blk,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPM/inputs/blk.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "blk values: "<< blk << std::endl;
  NumericVector row  = RcppDeepState_NumericVector();
  qs::c_qsave(row,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPM/inputs/row.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "row values: "<< row << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  qs::c_qsave(col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPM/inputs/col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  NumericVector rN(1);
  rN[0]  = RcppDeepState_double();
  qs::c_qsave(rN,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPM/inputs/rN.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rN values: "<< rN << std::endl;
  NumericVector cN(1);
  cN[0]  = RcppDeepState_double();
  qs::c_qsave(cN,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPM/inputs/cN.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cN values: "<< cN << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SPM(blk,row,col,rN[0],cN[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
