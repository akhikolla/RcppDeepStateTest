#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
NumericVector MeanCpp(NumericMatrix x){
  int b=x.ncol();
  NumericVector m(b);
  for (int i=0; i<b; i++) {
    m[i]=mean(x(_,i));
  }
  return m;
}

NumericVector VarCpp(NumericMatrix x){
  int a=x.nrow(), b=x.ncol();
  NumericVector v(b);
  if (a==1){
    return v;
  } else {
    for (int i=0; i<b; i++) {
      v[i]=var(x(_,i));
    }
  }
  return v;
}
// [[Rcpp::export]]

List OrderKmeansCpp(NumericMatrix x, int K=4, int num_init=10) {
  if (!Rf_isMatrix(x)) {
    stop("Dataset must be matrix form!");
  }
  int N = x.nrow(); // number of observations
  int D = x.ncol(); // dimension of each observation
  // There are M segments
  int M = K+1;
  // Change points number error handling
  if (N < M) {
    stop("Change point number too large or Input dimension error!");
  } else if (M == 1) {
    stop("No change point!");
  }
  double best_wgss_sum;
  NumericMatrix best_num_each;
  NumericVector best_wgss;
  NumericVector best_change_point;
  // special case, N == M
  if (N == M) {
    best_wgss_sum = 0;
    NumericMatrix num_each(N,1);
    best_num_each = num_each;
    std::fill(best_num_each.begin(),best_num_each.end(),1);
    NumericVector wgss(N);
    best_wgss = wgss;
    IntegerVector temp_best_change_point = seq(1,N);
    best_change_point = as<NumericVector>(temp_best_change_point);
  } else {
    // randomize initial change points several times to avoid local optima
    best_wgss_sum = R_PosInf;
    // set the random initialization times
    //if (num_init == "sqrt") {
    //  num_init = sqrt(dim(x)[1])
    //}
    for (int j=0; j<num_init; j++) {
      // store the within segment sum of squared distances to the segment mean (wgss)
      // in each dimension in each segment
      NumericMatrix num_each(M,1);
      NumericMatrix wgss_each(M,D);
      NumericMatrix mean_each(M,D);

      // Initialize change points, add N-th observation as the last change point so
      // there are K+1 change points
      NumericVector change_point=floor((N-2)*runif(K));
      change_point.push_back(N-1);
      change_point = unique(change_point);

      // make sure change points are unique
      while (change_point.length() < M) {
        change_point.push_back(floor((N-2)*runif(1)[0]));
        change_point=unique(change_point);
      }
      change_point = change_point.sort();

      // initialize for each segment the number of points, within segment sum of squares, and mean
      num_each[0] = change_point[0]+1;
      wgss_each(0,_) = VarCpp(x(Range(0,change_point[0]),_)) * (num_each[0]-1);
      mean_each(0,_) = MeanCpp(x(Range(0,change_point[0]),_));

      for (int i=1; i<M; i++) {
        num_each[i] = change_point[i] - change_point[i-1];
        wgss_each(i,_) = VarCpp(x(Range((change_point[i-1]+1),change_point[i]),_)) * (num_each[i]-1);
        mean_each(i,_) = MeanCpp(x(Range((change_point[i-1]+1),change_point[i]),_));
      }

      // scan the middle K change points
      // suppose that we are at the crossing of segments i and i+1
      NumericVector wgss(M);
      for (int i = 0; i < K; i++) {
        // consider if we should move the last part of segment i
        double best_gain_sum = R_NegInf;
        int best_ell;
        NumericMatrix best_candidatePart;
        if (num_each[i] > 1) {
        // scan all possible part that can be transformed form segment i to i+1
          for (int ell = 1; ell < num_each[i]; ell++) {
            NumericVector mean_candidatePart = MeanCpp(x(Range((change_point[i]-ell+1),change_point[i]),_));
            // the descrease in wgss of segment i
            NumericVector decrease = ell * num_each[i]/(num_each[i] - ell) * pow((mean_each(i,_) - mean_candidatePart),2);
            // the increase in wgss of segment i+1
            NumericVector increase  =ell * num_each[i+1]/(num_each[i+1] + ell) * pow((mean_each(i+1,_) - mean_candidatePart),2);
            // store the best candidate part than can be transformed from segment i to i+1
            double decrease_sum = sum(decrease);
            double increase_sum = sum(increase);
            double gain_sum = decrease_sum-increase_sum;
            if ( gain_sum > best_gain_sum) {
              best_gain_sum = gain_sum;
              best_ell = ell;
              best_candidatePart = x(Range((change_point[i]-ell+1),change_point[i]),_);
            }
          }
        }
        // If total wgss decrease, move the best candidate part from segment i to i+1,
        // and get new segment i and i+1, also update the corresponding mean, wgss adn change point.
        // If not, consider if we should move the first part of segment i+1
        if  (best_gain_sum > 0) {
          NumericVector best_mean_candidatePart = MeanCpp(best_candidatePart);
          mean_each(i,_) = (num_each[i] * mean_each(i,_) - best_ell * best_mean_candidatePart) / (num_each[i] - best_ell);
          mean_each(i+1,_) = (num_each[i+1] * mean_each(i+1,_) + best_ell * best_mean_candidatePart) / (num_each[i+1] + best_ell);
          change_point[i] = change_point[i] - best_ell;
          num_each[i] = num_each[i] - best_ell;
          num_each[i+1] = num_each[i+1] + best_ell;
          if (i == 0) {
            wgss_each(i,_) = VarCpp(x(Range(0,change_point[i]),_)) * (num_each[i]-1);
          } else {
            wgss_each(i,_) = VarCpp(x(Range(change_point[i-1]+1,change_point[i]),_)) * (num_each[i]-1);
          }
          wgss_each(i+1,_) = VarCpp(x(Range(change_point[i]+1,change_point[i+1]),_)) * (num_each[i+1]-1);
        } else {
          // consider if we should move the first part of segment i+1
          best_gain_sum = R_NegInf;
          if (num_each[i+1] > 1) {
            for (int ell = 1; ell < num_each[i+1]; ell++) {
              NumericVector mean_candidatePart = MeanCpp(x(Range((change_point[i]+1),change_point[i]+ell),_));
              NumericVector decrease = ell * num_each[i+1]/(num_each[i+1] - ell) * pow((mean_each(i+1,_) - mean_candidatePart),2);
              NumericVector increase = ell * num_each[i]/(num_each[i] + ell) * pow((mean_each(i,_) - mean_candidatePart),2);
              double decrease_sum = sum(decrease);
              double increase_sum = sum(increase);
              double gain_sum = decrease_sum-increase_sum;
              if ( gain_sum > best_gain_sum) {
                best_gain_sum = gain_sum;
                best_ell = ell;
                best_candidatePart = x(Range(change_point[i]+1,change_point[i]+ell),_);
              }
            }
          }
          if  (best_gain_sum > 0) {
            NumericVector best_mean_candidatePart = MeanCpp(best_candidatePart);
            mean_each(i+1,_) = (num_each[i+1] * mean_each(i+1,_) - best_ell * best_mean_candidatePart) / (num_each[i+1] - best_ell);
            mean_each(i,_) = (num_each[i] * mean_each(i,_) + best_ell * best_mean_candidatePart) / (num_each[i] + best_ell);
            change_point[i] = change_point[i] + best_ell;
            num_each[i] = num_each[i] + best_ell;
            num_each[i+1] = num_each[i+1] - best_ell;
            if (i == 0) {
              wgss_each(i,_) = VarCpp(x(Range(0,change_point[i]),_)) * (num_each[i]-1);
            } else {
              wgss_each(i,_) = VarCpp(x(Range(change_point[i-1]+1,change_point[i]),_)) * (num_each[i]-1);
            }
            wgss_each(i+1,_) = VarCpp(x(Range(change_point[i]+1,change_point[i+1]),_)) * (num_each[i+1]-1);
          }
        }
        // get the total wgss of each segment
        for (int i = 0; i < M; i++) {
          double row_sum = sum(wgss_each(i,_));
          wgss[i] = row_sum;
        }
      }
      //get the total wgss of all segments
      double wgss_sum = sum(wgss);
      // store the smallest total wgss among several initializations.
      if (best_wgss_sum > wgss_sum) {
        best_wgss_sum = wgss_sum;
        best_wgss = wgss;
        best_num_each = num_each;
        best_change_point = change_point;
      }
    }
  }
  // Delete the last observation from change points
  best_change_point = best_change_point + 1;
  best_change_point.erase(M-1);

  //k_changepints=list(wgss_sum=best_wgss_sum,num_each=best_num_each,wgss=best_wgss,change_point=best_change_point)
  return List::create(Named("wgss_sum") = best_wgss_sum,
                      Named("num_each") = best_num_each,
                      Named("wgss") = best_wgss,
                      Named("change_point") = best_change_point);
}

// [[Rcpp::export]]

List PriorRangeOrderKmeansCpp(NumericMatrix x,  List prior_range_x, int num_init=10) {
  if (!Rf_isMatrix(x)) {
    stop("Dataset must be matrix form!");
  }
  int N = x.nrow(); // number of observations
  int D = x.ncol(); // dimension of each observation
  // There are K change points
  int K = prior_range_x.size();
  // There are M segments
  int M = K+1;
  // Change points number error handling
  if (N < M) {
    stop("Change point number too large or Input dimension error!");
  } else if (M == 1) {
    stop("No change point!");
  }
  
  double best_wgss;
  NumericVector best_change_point;
  
  // randomize initial change points several times to avoid local optima
  best_wgss = R_PosInf;
  
  for (int j=0; j<num_init; j++) {
    // store the within segment sum of squared distances to the segment mean (wgss)
    // in each dimension in each segment
    NumericMatrix num_each(M,1);
    NumericMatrix wgss_each(M,D);
    NumericMatrix mean_each(M,D);
    
    // Initialize change points, add N-th observation as the last change point so
    // there are K+1 change points
    NumericVector change_point(K);
    for (int i=0; i < K; i++) {
      NumericVector prior_range(prior_range_x[i]);
      change_point[i] = floor((prior_range[0]-1)+(prior_range[1]-prior_range[0])*runif(1)[0]);
    }
    change_point.push_back(N-1);
    
    // initialize for each segment the number of points, within segment sum of squares, and mean
    num_each[0] = change_point[0]+1;
    wgss_each(0,_) = VarCpp(x(Range(0,change_point[0]),_)) * (num_each[0]-1);
    mean_each(0,_) = MeanCpp(x(Range(0,change_point[0]),_));
    
    for (int i=1; i<M; i++) {
      num_each[i] = change_point[i] - change_point[i-1];
      wgss_each(i,_) = VarCpp(x(Range((change_point[i-1]+1),change_point[i]),_)) * (num_each[i]-1);
      mean_each(i,_) = MeanCpp(x(Range((change_point[i-1]+1),change_point[i]),_));
    }
    
    // scan the middle K change points
    // suppose that we are at the crossing of segments i and i+1
    NumericVector wgss(D);
    for (int i = 0; i < K; i++) {
      // consider if we should move the last part of segment i
      double best_gain_sum = R_NegInf;
      int best_ell;
      NumericMatrix best_candidatePart;
      NumericVector prior_range(prior_range_x[i]);
      if (change_point[i] - (prior_range[0]-1) > 0) {
        // scan all possible part that can be transformed form segment i to i+1
        for (int ell = 1; ell <= (change_point[i] - (prior_range[0]-1)); ell++) {
          NumericVector mean_candidatePart = MeanCpp(x(Range((change_point[i]-ell+1),change_point[i]),_));
          // the descrease in wgss of segment i
          NumericVector decrease = ell * num_each[i]/(num_each[i] - ell) * pow((mean_each(i,_) - mean_candidatePart),2);
          // the increase in wgss of segment i+1
          NumericVector increase  =ell * num_each[i+1]/(num_each[i+1] + ell) * pow((mean_each(i+1,_) - mean_candidatePart),2);
          // store the best candidate part than can be transformed from segment i to i+1
          double decrease_sum = sum(decrease);
          double increase_sum = sum(increase);
          double gain_sum = decrease_sum-increase_sum;
          if ( gain_sum > best_gain_sum) {
            best_gain_sum = gain_sum;
            best_ell = ell;
            best_candidatePart = x(Range((change_point[i]-ell+1),change_point[i]),_);
          }
        }
      }
      // If total wgss decrease, move the best candidate part from segment i to i+1,
      // and get new segment i and i+1, also update the corresponding mean, wgss adn change point.
      // If not, consider if we should move the first part of segment i+1
      if  (best_gain_sum > 0) {
        NumericVector best_mean_candidatePart = MeanCpp(best_candidatePart);
        mean_each(i,_) = (num_each[i] * mean_each(i,_) - best_ell * best_mean_candidatePart) / (num_each[i] - best_ell);
        mean_each(i+1,_) = (num_each[i+1] * mean_each(i+1,_) + best_ell * best_mean_candidatePart) / (num_each[i+1] + best_ell);
        change_point[i] = change_point[i] - best_ell;
        num_each[i] = num_each[i] - best_ell;
        num_each[i+1] = num_each[i+1] + best_ell;
        if (i == 0) {
          wgss_each(i,_) = VarCpp(x(Range(0,change_point[i]),_)) * (num_each[i]-1);
        } else {
          wgss_each(i,_) = VarCpp(x(Range(change_point[i-1]+1,change_point[i]),_)) * (num_each[i]-1);
        }
        wgss_each(i+1,_) = VarCpp(x(Range(change_point[i]+1,change_point[i+1]),_)) * (num_each[i+1]-1);
      } else {
        // consider if we should move the first part of segment i+1
        best_gain_sum = R_NegInf;
        if ((prior_range[1]-1) - change_point[i] > 0) {
          for (int ell = 1; ell <= ((prior_range[1]-1) - change_point[i]); ell++) {
            if (ell < num_each[i+1]) {
              NumericVector mean_candidatePart = MeanCpp(x(Range((change_point[i]+1),change_point[i]+ell),_));
              NumericVector decrease = ell * num_each[i+1]/(num_each[i+1] - ell) * pow((mean_each(i+1,_) - mean_candidatePart),2);
              NumericVector increase = ell * num_each[i]/(num_each[i] + ell) * pow((mean_each(i,_) - mean_candidatePart),2);
              double decrease_sum = sum(decrease);
              double increase_sum = sum(increase);
              double gain_sum = decrease_sum-increase_sum;
              if ( gain_sum > best_gain_sum) {
                best_gain_sum = gain_sum;
                best_ell = ell;
                best_candidatePart = x(Range(change_point[i]+1,change_point[i]+ell),_);
              }
            }
          }
        }
        if  (best_gain_sum > 0) {
          NumericVector best_mean_candidatePart = MeanCpp(best_candidatePart);
          mean_each(i+1,_) = (num_each[i+1] * mean_each(i+1,_) - best_ell * best_mean_candidatePart) / (num_each[i+1] - best_ell);
          mean_each(i,_) = (num_each[i] * mean_each(i,_) + best_ell * best_mean_candidatePart) / (num_each[i] + best_ell);
          change_point[i] = change_point[i] + best_ell;
          num_each[i] = num_each[i] + best_ell;
          num_each[i+1] = num_each[i+1] - best_ell;
          if (i == 0) {
            wgss_each(i,_) = VarCpp(x(Range(0,change_point[i]),_)) * (num_each[i]-1);
          } else {
            wgss_each(i,_) = VarCpp(x(Range(change_point[i-1]+1,change_point[i]),_)) * (num_each[i]-1);
          }
          wgss_each(i+1,_) = VarCpp(x(Range(change_point[i]+1,change_point[i+1]),_)) * (num_each[i+1]-1);
        }
      }
      // get the wgss of all segments with original dimension
      for (int i = 0; i < D; i++) {
        double col_sum = sum(wgss_each(_,i));
        wgss[i] = col_sum;
      }
    }
    // get the total wgss of all dimensions
    double wgss_sum = sum(wgss);
    // store the smallest total wgss among several initializations.
    if (best_wgss > wgss_sum) {
      best_wgss = wgss_sum;
      best_change_point = change_point;
    }
  }
  
  // Delete the last observation from change points
  best_change_point = best_change_point + 1;
  best_change_point.erase(M-1);
  
  return List::create(Named("num_change_point") = K,
                      Named("change_point") = best_change_point);
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//


