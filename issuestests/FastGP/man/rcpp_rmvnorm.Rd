\name{rcpp_rmvnorm}
\alias{rcpp_rmvnorm}
\alias{rcpp_rmvnorm_stable}
\alias{rcpp_log_dmvnorm}
\title{Multivariate Normal Sampling and Log-Density Evaluation}
\description{These functions allow for the sampling of and evaluation of the log-density of a multivariate normal vector.}
\usage{
rcpp_log_dmvnorm(S,mu,x, istoep)
rcpp_rmvnorm(n,S,mu)
rcpp_rmvnorm_stable(n,S,mu)
}
\arguments{
 \item{S}{Covariance matrix of associated multivariate normal.}
 \item{n}{Number of (independent) samples to generate.}
 \item{mu}{Mean vector.}
 \item{x}{Vector of observations to evaluate the log-density of.}
 \item{istoep}{set this to \code{TRUE} if S is Toeplitz.}
}
\author{Giri Gopalan gopalan88@gmail.com}
\examples{
#See demo/FastGPdemo.R
}

