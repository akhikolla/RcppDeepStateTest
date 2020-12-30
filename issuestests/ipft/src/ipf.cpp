#include <Rcpp.h>
#include <cmath>

using namespace Rcpp;

double lgd(NumericVector x, NumericVector y, double sd, double epsilon) {
  double g = 0;
  double gSum = 0;
  double pi = 3.141592653589793238463;
  double t1 = 1 / (std::sqrt(2 * pi * std::pow(sd, 2)));
  double t2 = -1 / (2 * std::pow(sd, 2));
  for (int i = 0; i < x.length(); i++) {
    if (R_IsNA(x[i]) || R_IsNA(y[i])) {
      continue;
    }
    if (x[i] != 0 && y[i] != 0) {
      g = t1 * std::exp(t2 * std::pow(x[i] - y[i], 2));
    } else {
      g = 0;
    }
    if (g < epsilon) {
      g = epsilon;
    }
    gSum += std::log(g);
  }
  return -gSum;
}

double plgd(NumericVector x, NumericVector y, double sd, double epsilon, double alpha, double threshold) {
  double p = 0;
  double pSum = 0;
  for (int i = 0; i < x.length(); i++) {
    p = 0;
    if (R_IsNA(x[i]) || R_IsNA(y[i])) {
      continue;
    }
    if (x[i] != 0 && y[i] == 0) {
      if (x[i] > threshold) {
        p = x[i] - threshold;
      }
    } else if (y[i] != 0 && x[i] == 0) {
      if (y[i] > threshold) {
        p = y[i] - threshold;
      }
    }
    pSum += p;
  }
  return lgd(x, y, sd, epsilon) + alpha * pSum;
}

double norm(NumericVector x, NumericVector y, double normVal) {
  double d = 0;
  for (int i = 0; i < x.length(); i++) {
    if (!R_IsNA(x[i]) && !R_IsNA(y[i])) {
      d = d + std::pow(fabs(x[i] - y[i]), normVal);
    }
  }
  return std::pow(d, 1 / normVal);
}

double manhattan(NumericVector x, NumericVector y) {
  double d = 0;
  for (int i = 0; i < x.length(); i++) {
    if (!R_IsNA(x[i]) && !R_IsNA(y[i])) {
      d = d + std::fabs(x[i] - y[i]);
    }
  }
  return d;
}

// [[Rcpp::export]]
NumericMatrix ipfLGD(NumericMatrix train, NumericMatrix test, double sd, double epsilon) {
  NumericMatrix distanceMatrix(test.nrow(), train.nrow());
  for (int itrain = 0; itrain < train.nrow(); itrain++) {
    for (int itest = 0; itest < test.nrow(); itest++) {
      distanceMatrix(itest, itrain) = lgd(train(itrain, _), test(itest, _), sd, epsilon);
    }
  }
  return distanceMatrix;
}

// [[Rcpp::export]]
NumericMatrix ipfPLGD(NumericMatrix train, NumericMatrix test, double sd, double epsilon, double alpha, double threshold) {
  NumericMatrix distanceMatrix(test.nrow(), train.nrow());
  for (int itrain = 0; itrain < train.nrow(); itrain++) {
    for (int itest = 0; itest < test.nrow(); itest++) {
      distanceMatrix(itest, itrain) = plgd(train(itrain, _), test(itest, _), sd, epsilon, alpha, threshold);
    }
  }
  return distanceMatrix;
}

// [[Rcpp::export]]
NumericMatrix ipfEuclidean(NumericMatrix train, NumericMatrix test) {
  NumericMatrix distanceMatrix(test.nrow(), train.nrow());
  for (int itrain = 0; itrain < train.nrow(); itrain++) {
    for (int itest = 0; itest < test.nrow(); itest++) {
      distanceMatrix(itest, itrain) = norm(train(itrain, _), test(itest, _), 2);
    }
  }
  return distanceMatrix;
}

// [[Rcpp::export]]
NumericMatrix ipfManhattan(NumericMatrix train, NumericMatrix test) {
  NumericMatrix distanceMatrix(test.nrow(), train.nrow());
  for (int itrain = 0; itrain < train.nrow(); itrain++) {
    for (int itest = 0; itest < test.nrow(); itest++) {
      distanceMatrix(itest, itrain) = manhattan(train(itrain, _), test(itest, _));
    }
  }
  return distanceMatrix;
}


// [[Rcpp::export]]
NumericMatrix ipfNormDistance(NumericMatrix train, NumericMatrix test, double normVal) {
  NumericMatrix distanceMatrix(test.nrow(), train.nrow());
  for (int itrain = 0; itrain < train.nrow(); itrain++) {
    for (int itest = 0; itest < test.nrow(); itest++) {
      distanceMatrix(itest, itrain) = norm(train(itrain, _), test(itest, _), normVal);
    }
  }
  return distanceMatrix;
}
