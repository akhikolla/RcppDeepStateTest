\name{rcpp_matrix_ops}
\alias{tinv}
\alias{rcppeigen_invert_matrix}
\alias{rcppeigen_get_det}
\alias{rcppeigen_get_chol}
\alias{rcppeigen_get_chol_stable}
\alias{rcppeigen_get_chol_diag}
\alias{rcppeigen_get_diag}
\alias{durbin}
\alias{trench}
\alias{rcpp_distance}
\title{Matrix Operations Using Rcpp and RcppEigen}
\description{
Performs useful matrix operations using Rcpp and RcppEigen. 
}
\usage{
rcppeigen_invert_matrix(A)
rcppeigen_get_det(A)
rcppeigen_get_chol(A)
rcppeigen_get_chol_stable(A)
rcppeigen_get_chol_diag(A)
tinv(A)
}
\arguments{
  \item{A}{Matrix to perform operation on.}
  }
\details{
Functions with "rcppeigen" directly call RcppEigen implementations of the associated functions; rcppeigen_get_chol_stable retrieves L and rcppeigen_get_chol_diag(A) retrieves D in A = LDL^T form, whereas rcppeigen_get_chol(A) retrieves L in A = LL^T form.  Thanks to Jared Knowles who pointed out that the former variant is more stable (with a potential speed trade-off) and has found it useful for his package merTools.  \code{tinv} inverts a symmetric Toeplitz matrix using methods from Trench and Durbin from "Matrix Computations" by Golub and Van Loan using Rcpp.
  }
\author{gopalan88@gmail.com}
\examples{
# See demo/FastGPdemo.R
}

