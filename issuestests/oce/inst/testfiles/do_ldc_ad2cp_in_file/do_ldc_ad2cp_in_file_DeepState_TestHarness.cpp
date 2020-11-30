#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_ldc_ad2cp_in_file(CharacterVector filename, IntegerVector from, IntegerVector to, IntegerVector by);

TEST(oce_deepstate_test,do_ldc_ad2cp_in_file_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector filename  = RcppDeepState_CharacterVector();
  qs::c_qsave(filename,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/inputs/filename.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "filename values: "<< filename << std::endl;
  IntegerVector from  = RcppDeepState_IntegerVector();
  qs::c_qsave(from,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/inputs/from.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "from values: "<< from << std::endl;
  IntegerVector to  = RcppDeepState_IntegerVector();
  qs::c_qsave(to,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/inputs/to.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "to values: "<< to << std::endl;
  IntegerVector by  = RcppDeepState_IntegerVector();
  qs::c_qsave(by,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/inputs/by.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "by values: "<< by << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_ldc_ad2cp_in_file(filename,from,to,by);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
