#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List bsplitC(NumericMatrix Dmat, NumericMatrix Xmat, NumericVector parm);

TEST(icRSF_deepstate_test,bsplitC_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Dmat  = RcppDeepState_NumericMatrix();
  std::string Dmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/libFuzzer_bsplitC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Dmat.qs";
  qs::c_qsave(Dmat,Dmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dmat values: "<< Dmat << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  std::string Xmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/libFuzzer_bsplitC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xmat.qs";
  qs::c_qsave(Xmat,Xmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  std::string parm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/libFuzzer_bsplitC/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_parm.qs";
  qs::c_qsave(parm,parm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bsplitC(Dmat,Xmat,parm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
