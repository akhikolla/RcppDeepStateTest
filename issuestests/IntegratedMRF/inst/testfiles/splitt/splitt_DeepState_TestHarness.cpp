#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List splitt(NumericMatrix X, NumericMatrix Y, int m_feature, NumericVector Index, NumericMatrix Inv_Cov_Y, int Command, NumericVector ff);

TEST(IntegratedMRF_deepstate_test,splitt_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  IntegerVector m_feature(1);
  m_feature[0]  = RcppDeepState_int();
  qs::c_qsave(m_feature,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/m_feature.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_feature values: "<< m_feature << std::endl;
  NumericVector Index  = RcppDeepState_NumericVector();
  qs::c_qsave(Index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/Index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Index values: "<< Index << std::endl;
  NumericMatrix Inv_Cov_Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Inv_Cov_Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/Inv_Cov_Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Inv_Cov_Y values: "<< Inv_Cov_Y << std::endl;
  IntegerVector Command(1);
  Command[0]  = RcppDeepState_int();
  qs::c_qsave(Command,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/Command.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Command values: "<< Command << std::endl;
  NumericVector ff  = RcppDeepState_NumericVector();
  qs::c_qsave(ff,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/splitt/inputs/ff.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ff values: "<< ff << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    splitt(X,Y,m_feature[0],Index,Inv_Cov_Y,Command[0],ff);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
