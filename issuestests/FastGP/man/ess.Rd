\name{ess}
\alias{ess}
\title{Sampling from a Bayesian model with a multivariate normal prior distribution}
\description{
  This function uses elliptical slice sampling to sample from a Bayesian model in which the prior is multivariate normal (JMLR Murray, Adams, and MacKay 2010)}
\usage{
ess(log.lik,Y, Sig, N_mcmc,burn_in,N,flag)
}
\arguments{
 \item{log.lik}{Log-lik function in model which is assumed to take two arguments: the first contains the parameters/latent variables and the second the observed data Y}
 \item{Y}{Observed data.}
 \item{Sig}{Covariance matrix associated with the prior distribution on the parameters/latent variable vector. }
 \item{N_mcmc}{Number of desired mcmc samples.}
 \item{burn_in}{Number of burn-in iterations.}
 \item{N}{Dimensionality of parameter/latent variable vector.}
 \item{flag}{Set to TRUE for MASS implementation of mvrnorm (which may be more stable but slow), FALSE for FastGP implementation of rcpp_rmvnorm (which is faster but less stable)}
 }
\author{Giri Gopalan gopalan88@gmail.com}
\examples{
# See demo/FastGPdemo.r.
}

