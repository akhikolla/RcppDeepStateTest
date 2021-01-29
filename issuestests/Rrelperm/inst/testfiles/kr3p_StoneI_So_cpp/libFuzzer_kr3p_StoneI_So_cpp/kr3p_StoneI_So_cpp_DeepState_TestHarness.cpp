#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix kr3p_StoneI_So_cpp(double SWCON, double SWCRIT, double SOIRW, double SORW, double SOIRG, double SORG, double SGCON, double SGCRIT, double KRWIRO, double KROCW, double KRGCL, double NW, double NOW, double NG, double NOG, int NP);

TEST(Rrelperm_deepstate_test,kr3p_StoneI_So_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  std::string SWCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SWCON.qs";
  qs::c_qsave(SWCON,SWCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SWCRIT(1);
  SWCRIT[0]  = RcppDeepState_double();
  std::string SWCRIT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SWCRIT.qs";
  qs::c_qsave(SWCRIT,SWCRIT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCRIT values: "<< SWCRIT << std::endl;
  NumericVector SOIRW(1);
  SOIRW[0]  = RcppDeepState_double();
  std::string SOIRW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SOIRW.qs";
  qs::c_qsave(SOIRW,SOIRW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SOIRW values: "<< SOIRW << std::endl;
  NumericVector SORW(1);
  SORW[0]  = RcppDeepState_double();
  std::string SORW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SORW.qs";
  qs::c_qsave(SORW,SORW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORW values: "<< SORW << std::endl;
  NumericVector SOIRG(1);
  SOIRG[0]  = RcppDeepState_double();
  std::string SOIRG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SOIRG.qs";
  qs::c_qsave(SOIRG,SOIRG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SOIRG values: "<< SOIRG << std::endl;
  NumericVector SORG(1);
  SORG[0]  = RcppDeepState_double();
  std::string SORG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SORG.qs";
  qs::c_qsave(SORG,SORG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORG values: "<< SORG << std::endl;
  NumericVector SGCON(1);
  SGCON[0]  = RcppDeepState_double();
  std::string SGCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SGCON.qs";
  qs::c_qsave(SGCON,SGCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SGCON values: "<< SGCON << std::endl;
  NumericVector SGCRIT(1);
  SGCRIT[0]  = RcppDeepState_double();
  std::string SGCRIT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_SGCRIT.qs";
  qs::c_qsave(SGCRIT,SGCRIT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SGCRIT values: "<< SGCRIT << std::endl;
  NumericVector KRWIRO(1);
  KRWIRO[0]  = RcppDeepState_double();
  std::string KRWIRO_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_KRWIRO.qs";
  qs::c_qsave(KRWIRO,KRWIRO_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KRWIRO values: "<< KRWIRO << std::endl;
  NumericVector KROCW(1);
  KROCW[0]  = RcppDeepState_double();
  std::string KROCW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_KROCW.qs";
  qs::c_qsave(KROCW,KROCW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROCW values: "<< KROCW << std::endl;
  NumericVector KRGCL(1);
  KRGCL[0]  = RcppDeepState_double();
  std::string KRGCL_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_KRGCL.qs";
  qs::c_qsave(KRGCL,KRGCL_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KRGCL values: "<< KRGCL << std::endl;
  NumericVector NW(1);
  NW[0]  = RcppDeepState_double();
  std::string NW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NW.qs";
  qs::c_qsave(NW,NW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NW values: "<< NW << std::endl;
  NumericVector NOW(1);
  NOW[0]  = RcppDeepState_double();
  std::string NOW_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NOW.qs";
  qs::c_qsave(NOW,NOW_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOW values: "<< NOW << std::endl;
  NumericVector NG(1);
  NG[0]  = RcppDeepState_double();
  std::string NG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NG.qs";
  qs::c_qsave(NG,NG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NG values: "<< NG << std::endl;
  NumericVector NOG(1);
  NOG[0]  = RcppDeepState_double();
  std::string NOG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NOG.qs";
  qs::c_qsave(NOG,NOG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOG values: "<< NOG << std::endl;
  IntegerVector NP(1);
  NP[0]  = RcppDeepState_int();
  std::string NP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr3p_StoneI_So_cpp/libFuzzer_kr3p_StoneI_So_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NP.qs";
  qs::c_qsave(NP,NP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NP values: "<< NP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kr3p_StoneI_So_cpp(SWCON[0],SWCRIT[0],SOIRW[0],SORW[0],SOIRG[0],SORG[0],SGCON[0],SGCRIT[0],KRWIRO[0],KROCW[0],KRGCL[0],NW[0],NOW[0],NG[0],NOG[0],NP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
