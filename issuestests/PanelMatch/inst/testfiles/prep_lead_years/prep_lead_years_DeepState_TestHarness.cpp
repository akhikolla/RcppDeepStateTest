#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List prep_lead_years(Rcpp::NumericVector ts, Rcpp::NumericVector lead_window);

TEST(PanelMatch_deepstate_test,prep_lead_years_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  qs::c_qsave(ts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/prep_lead_years/inputs/ts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  NumericVector lead_window  = RcppDeepState_NumericVector();
  qs::c_qsave(lead_window,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/prep_lead_years/inputs/lead_window.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lead_window values: "<< lead_window << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    prep_lead_years(ts,lead_window);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
