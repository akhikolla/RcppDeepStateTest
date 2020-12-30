#' Correlation-Adjusted Regression Survival Scores
#'
#' @name carSurv-package
#' @aliases carSurv-package
#' @docType package
#' @description Contains functions to estimate the Correlation-Adjusted Regression Survival (CARS) Scores. 
#' The main function is \code{\link{carSurvScore}}, which estimates CARS scores of each variable. 
#' The higher the absolute values of CARS scores, the higher the variable importance. 
#' Additionally there is the function \code{\link{carVarSelect}} to select cut-off thresholds 
#' to separate variables associated with survival from noise variables. There are two possible 
#' cut-off threshold options: False non-discovery rate q-values and empirical quantiles of the 
#' raw scores. 
#' @details
#' Package:	 carSurv \cr
#' \cr
#' Type:	 Package \cr
#' \cr
#' Version:	 1.0.0 \cr
#' \cr
#' Date:	 2018-02-24 \cr
#' \cr
#' License:	 GPL-3
#' @author Thomas Welchowski (Maintainer) \email{welchow@imbie.meb.uni-bonn.de}
#' @references
#' Welchowski, T. and Zuber, V. and Schmid, M., (2018), Correlation-Adjusted Regression Survival Scores for High-Dimensional Variable Selection, <arXiv:1802.08178>
#' 
#' Zuber, V. and Strimmer, K., (2011), High-Dimensional Regression and Variable 
#' Selection Using CAR Scores, Statistical Applications in Genetics and Molecular Biology
#' 
#' Schaefer, J. and Strimmer, K., (2005), A Shrinkage Approach to Large-Scale Covariance Matrix Estimation and Implications for Functional Genomics,
#' Statistical Applications in Genetics and Molecular Biology
#' 
#' Van der Laan, M. J. and Robins, J. M., (2003), Unified Methods for Censored Longitudinal Data and Causality, Springer Series in Statistics
#' Strimmer, K., (2008), A unified approach to false discovery rate estimation, BMC Bioinformatics
NULL

# Namespace code
#' @useDynLib carSurv, .registration = TRUE
#' @importFrom Rcpp sourceCpp
#' @importFrom survival Surv
#' @importFrom corpcor crossprod.powcor.shrink
#' @importFrom mboost IPCweights
#' @importFrom fdrtool fdrtool
#' @importFrom stats quantile var
NULL
