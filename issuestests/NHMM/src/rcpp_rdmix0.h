#ifndef rcpp_rcpp_dmix0_hpp
#define rcpp_rcpp_dmix0_hpp

Rcpp::NumericVector rcpp_dmix0(int fam, double y, Rcpp::NumericVector ppp,     Rcpp::NumericVector par1, Rcpp::NumericVector par2);

#endif


#ifndef rcpp_rcpp_rmix0_hpp
#define rcpp_rcpp_rmix0_hpp

double rcpp_rmix0(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2);

#endif


#ifndef rcpp_rcpp_dmix_hpp
#define rcpp_rcpp_dmix_hpp

Rcpp::NumericVector rcpp_dmix(int fam, double y, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2);  

#endif


#ifndef rcpp_rcpp_rmix_hpp
#define rcpp_rcpp_rmix_hpp

double rcpp_rmix(int fam, Rcpp::NumericVector ppp, Rcpp::NumericVector par1, Rcpp::NumericVector par2);

#endif
