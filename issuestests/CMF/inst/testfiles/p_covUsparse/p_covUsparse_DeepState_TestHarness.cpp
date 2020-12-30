#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_covUsparse(NumericMatrix Xm, NumericMatrix Cm, NumericMatrix OUm, NumericMatrix OCm, NumericVector I, NumericVector T);

TEST(CMF_deepstate_test,p_covUsparse_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/Xm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix Cm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Cm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/Cm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cm values: "<< Cm << std::endl;
  NumericMatrix OUm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(OUm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/OUm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OUm values: "<< OUm << std::endl;
  NumericMatrix OCm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(OCm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/OCm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OCm values: "<< OCm << std::endl;
  NumericVector I  = RcppDeepState_NumericVector();
  qs::c_qsave(I,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/I.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  qs::c_qsave(T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/inputs/T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_covUsparse(Xm,Cm,OUm,OCm,I,T);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
