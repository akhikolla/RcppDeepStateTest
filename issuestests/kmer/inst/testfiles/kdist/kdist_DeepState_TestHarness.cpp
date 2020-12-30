#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix kdist(NumericMatrix x, IntegerVector from, IntegerVector to, IntegerVector seqlengths, int k);

TEST(kmer_deepstate_test,kdist_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector from  = RcppDeepState_IntegerVector();
  qs::c_qsave(from,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/inputs/from.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "from values: "<< from << std::endl;
  IntegerVector to  = RcppDeepState_IntegerVector();
  qs::c_qsave(to,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/inputs/to.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "to values: "<< to << std::endl;
  IntegerVector seqlengths  = RcppDeepState_IntegerVector();
  qs::c_qsave(seqlengths,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/inputs/seqlengths.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seqlengths values: "<< seqlengths << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  qs::c_qsave(k,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kmer/inst/testfiles/kdist/inputs/k.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kdist(x,from,to,seqlengths,k[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
