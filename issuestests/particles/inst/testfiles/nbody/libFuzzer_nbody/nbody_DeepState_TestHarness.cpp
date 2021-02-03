#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix nbody(NumericMatrix pos, NumericVector strength, double theta, double min_dist, double max_dist, double alpha);

TEST(particles_deepstate_test,nbody_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix pos  = RcppDeepState_NumericMatrix();
  std::string pos_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pos.qs";
  qs::c_qsave(pos,pos_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos values: "<< pos << std::endl;
  NumericVector strength  = RcppDeepState_NumericVector();
  std::string strength_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_strength.qs";
  qs::c_qsave(strength,strength_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "strength values: "<< strength << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector min_dist(1);
  min_dist[0]  = RcppDeepState_double();
  std::string min_dist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_min_dist.qs";
  qs::c_qsave(min_dist,min_dist_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_dist values: "<< min_dist << std::endl;
  NumericVector max_dist(1);
  max_dist[0]  = RcppDeepState_double();
  std::string max_dist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_dist.qs";
  qs::c_qsave(max_dist,max_dist_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_dist values: "<< max_dist << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/libFuzzer_nbody/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nbody(pos,strength,theta[0],min_dist[0],max_dist[0],alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
