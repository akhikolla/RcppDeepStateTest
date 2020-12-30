#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_updatePseudoData(NumericMatrix Xm, NumericMatrix U1m, NumericMatrix U2m, NumericVector Rv, NumericVector Cv);

TEST(CMF_deepstate_test,p_updatePseudoData_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/inputs/Xm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix U1m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(U1m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/inputs/U1m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U1m values: "<< U1m << std::endl;
  NumericMatrix U2m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(U2m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/inputs/U2m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U2m values: "<< U2m << std::endl;
  NumericVector Rv  = RcppDeepState_NumericVector();
  qs::c_qsave(Rv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/inputs/Rv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rv values: "<< Rv << std::endl;
  NumericVector Cv  = RcppDeepState_NumericVector();
  qs::c_qsave(Cv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/inputs/Cv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cv values: "<< Cv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_updatePseudoData(Xm,U1m,U2m,Rv,Cv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
