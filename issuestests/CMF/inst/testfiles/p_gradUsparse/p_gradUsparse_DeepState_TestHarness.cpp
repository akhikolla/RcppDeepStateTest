#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_gradUsparse(NumericMatrix Xm, NumericMatrix Gm, NumericMatrix CUm, NumericMatrix OUm, NumericMatrix Cm, NumericVector I, NumericVector T, NumericVector Rowm, NumericVector Colm);

TEST(CMF_deepstate_test,p_gradUsparse_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/Xm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix Gm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Gm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/Gm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Gm values: "<< Gm << std::endl;
  NumericMatrix CUm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(CUm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/CUm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "CUm values: "<< CUm << std::endl;
  NumericMatrix OUm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(OUm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/OUm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OUm values: "<< OUm << std::endl;
  NumericMatrix Cm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Cm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/Cm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cm values: "<< Cm << std::endl;
  NumericVector I  = RcppDeepState_NumericVector();
  qs::c_qsave(I,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/I.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  qs::c_qsave(T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector Rowm  = RcppDeepState_NumericVector();
  qs::c_qsave(Rowm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/Rowm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rowm values: "<< Rowm << std::endl;
  NumericVector Colm  = RcppDeepState_NumericVector();
  qs::c_qsave(Colm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/inputs/Colm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Colm values: "<< Colm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_gradUsparse(Xm,Gm,CUm,OUm,Cm,I,T,Rowm,Colm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
