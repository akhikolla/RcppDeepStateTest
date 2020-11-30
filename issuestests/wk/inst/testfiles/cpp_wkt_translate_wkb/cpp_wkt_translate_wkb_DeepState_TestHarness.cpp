#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_wkt_translate_wkb(CharacterVector wkt, int includeZ, int includeM, int includeSRID, int endian, int bufferSize);

TEST(wk_deepstate_test,cpp_wkt_translate_wkb_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector wkt  = RcppDeepState_CharacterVector();
  qs::c_qsave(wkt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/wkt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wkt values: "<< wkt << std::endl;
  IntegerVector includeZ(1);
  includeZ[0]  = RcppDeepState_int();
  qs::c_qsave(includeZ,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/includeZ.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeZ values: "<< includeZ << std::endl;
  IntegerVector includeM(1);
  includeM[0]  = RcppDeepState_int();
  qs::c_qsave(includeM,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/includeM.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeM values: "<< includeM << std::endl;
  IntegerVector includeSRID(1);
  includeSRID[0]  = RcppDeepState_int();
  qs::c_qsave(includeSRID,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/includeSRID.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeSRID values: "<< includeSRID << std::endl;
  IntegerVector endian(1);
  endian[0]  = RcppDeepState_int();
  qs::c_qsave(endian,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/endian.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "endian values: "<< endian << std::endl;
  IntegerVector bufferSize(1);
  bufferSize[0]  = RcppDeepState_int();
  qs::c_qsave(bufferSize,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wkb/inputs/bufferSize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bufferSize values: "<< bufferSize << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_wkt_translate_wkb(wkt,includeZ[0],includeM[0],includeSRID[0],endian[0],bufferSize[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
