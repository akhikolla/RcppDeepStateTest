\name{ds_1}
\alias{ds_1}
\docType{package}
\title{
  Non-parametric one-sample hypothesis testing via dynamic slicing
}
\description{
  Non-parametric one-sample hypothesis testing via dynamic slicing. By mapping sample values to the quantile of null distribution, \code{ds_1} test whether they follow uniform distribution on [0, 1] via a regularized likelihood-ratio. Its calculated is based on a dynamic programming procedure.
}
\usage{
  ds_1(y, lambda, alpha)
}
\arguments{
  \item{y}{Vector: quantiles of observations according to null distribution.}
  \item{lambda}{\code{lambda} penalizes the number of slices to avoid too many slices. \code{lambda} should be greater than 0.}
  \item{alpha}{\code{alpha} penalizes both the width and the number of slices to avoid too many slices and degenerate slice (interval). \code{alpha} should be greater than 1.} 
}
\value{
  Value of dynamic slicing statistic for one-sample test. It is nonnegative. The null hypothesis that observations are from the null distribution is rejected if this statistic is greater than zero, otherwise accept the null hypothesis.
}
\seealso{
  \code{\link{ds_eqp_1}}.
}
\examples{
n <- 100
mu <- 0.5
x <- rnorm(n, mu, 1)
y <- pnorm(sort(x), 0, 1) 
lambda <- 1.0
alpha <- 1.0
dsres <- ds_1(y, lambda, alpha)
}
