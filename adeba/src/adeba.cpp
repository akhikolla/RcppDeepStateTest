#include <Rcpp.h>
using namespace Rcpp;


//' Check for columns with constant values
//'
//' @param x A numeric matrix.
//' @return A logical vector containing \code{TRUE} if all elements of a column
//'   are identical.
//' @noRd
// [[Rcpp::export]]
LogicalVector find_constants(NumericMatrix x) {
    int i;
    int n = x.nrow();
    int p = x.ncol();
    LogicalVector is_constant(p);
    for(int j = 0; j < p; j++){
        i = 1;
        while(i < n && x(i,j) == x(0,j)) i++;
        is_constant(j) = i == n;
    }
    return is_constant ;
}

//' Check if a vector contains only one unique value
//'
//' @param x A numeric vector with no missing values.
//' @return A logical that is \code{TRUE} if all elements were identical,
//'   otherwise \code{FALSE}.
//' @noRd
// [[Rcpp::export]]
LogicalVector is_constant(NumericVector x) {
    for(int i = 1; i < x.size(); i++)
        if(x[i] != x[0]) return false;
    return true;
}

//' Calculate bandwithds from parameters
//' 
//' @param object ADEBA estimate.
//' @return A matrix of dimension D x A*B where D is the number of
//'   observations in the data set, A is the number of alpha values, and B is the
//'   number of beta values.
//' @author Christofer \enc{Bäcklin}{Backlin}
//' @noRd
// [[Rcpp::export]]
NumericMatrix get_bandwidths(NumericVector pilot,
                             NumericVector alpha, NumericVector beta){
    int ndata = pilot.size();
    int nparam = alpha.size();
    int i,j;
    NumericMatrix bandwidths(ndata, nparam);
    for(i = 0; i < ndata; i++){
        for(j = 0; j < nparam; j++){
            bandwidths(i,j) = alpha[j] / pow(pilot[i], beta[j]);
        }
    }
    return bandwidths;
}

