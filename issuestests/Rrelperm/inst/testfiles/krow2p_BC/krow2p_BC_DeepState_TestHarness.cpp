#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double krow2p_BC(double SW, double SWCON, double SORW, double KROCW, double NOW);

TEST(Rrelperm_deepstate_test,krow2p_BC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector SW(1);
  SW[0]  = RcppDeepState_double();
  qs::c_qsave(SW,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/inputs/SW.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SW values: "<< SW << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  qs::c_qsave(SWCON,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/inputs/SWCON.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SORW(1);
  SORW[0]  = RcppDeepState_double();
  qs::c_qsave(SORW,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/inputs/SORW.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORW values: "<< SORW << std::endl;
  NumericVector KROCW(1);
  KROCW[0]  = RcppDeepState_double();
  qs::c_qsave(KROCW,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/inputs/KROCW.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROCW values: "<< KROCW << std::endl;
  NumericVector NOW(1);
  NOW[0]  = RcppDeepState_double();
  qs::c_qsave(NOW,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/krow2p_BC/inputs/NOW.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOW values: "<< NOW << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    krow2p_BC(SW[0],SWCON[0],SORW[0],KROCW[0],NOW[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
