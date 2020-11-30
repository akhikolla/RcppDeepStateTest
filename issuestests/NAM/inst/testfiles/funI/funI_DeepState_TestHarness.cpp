#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector funI(NumericVector col, int fam, int finsiz, int f);

TEST(NAM_deepstate_test,funI_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  qs::c_qsave(col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/inputs/col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  qs::c_qsave(fam,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/inputs/fam.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  IntegerVector finsiz(1);
  finsiz[0]  = RcppDeepState_int();
  qs::c_qsave(finsiz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/inputs/finsiz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "finsiz values: "<< finsiz << std::endl;
  IntegerVector f(1);
  f[0]  = RcppDeepState_int();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/inputs/f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    funI(col,fam[0],finsiz[0],f[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
