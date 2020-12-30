#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double FOM_AFROC1(NumericMatrix nl, NumericMatrix ll, NumericVector n_lesions_per_image, NumericVector max_cases, int max_nl, int max_ll);

TEST(RJafroc_deepstate_test,FOM_AFROC1_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix nl  = RcppDeepState_NumericMatrix();
  qs::c_qsave(nl,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/nl.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nl values: "<< nl << std::endl;
  NumericMatrix ll  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ll,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/ll.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ll values: "<< ll << std::endl;
  NumericVector n_lesions_per_image  = RcppDeepState_NumericVector();
  qs::c_qsave(n_lesions_per_image,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/n_lesions_per_image.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_lesions_per_image values: "<< n_lesions_per_image << std::endl;
  NumericVector max_cases  = RcppDeepState_NumericVector();
  qs::c_qsave(max_cases,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/max_cases.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_cases values: "<< max_cases << std::endl;
  IntegerVector max_nl(1);
  max_nl[0]  = RcppDeepState_int();
  qs::c_qsave(max_nl,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/max_nl.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_nl values: "<< max_nl << std::endl;
  IntegerVector max_ll(1);
  max_ll[0]  = RcppDeepState_int();
  qs::c_qsave(max_ll,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/FOM_AFROC1/inputs/max_ll.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_ll values: "<< max_ll << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    FOM_AFROC1(nl,ll,n_lesions_per_image,max_cases,max_nl[0],max_ll[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
