\name{ds_test}
\alias{ds_test}
\title{
  Hypothesis testing via dynamic slicing
}
\description{
  Perform a one- or \emph{K}-sample (\eqn{K > 1}) hypothesis testing via dynamic slicing.
}
\usage{
  ds_test(y, x, ..., type = c("ds", "eqp"), lambda = 1, alpha = 1, rounds = 0)
}
\arguments{
  \item{y}{A numeric vector of data values.}
  \item{x}{Either an integer vector of data values, from 0 to \eqn{K-1}, or a character string naming a cumulative distribution function or an actual cumulative distribution function such as \code{pnorm}. Only continuous CDFs are valid.}
  \item{...}{Parameters of the distribution specified (as a character string) by \code{x}.}
  \item{type}{Methods applied for dynamic slicing. "\code{ds}" (default) stands for original dynamic slicing scheme. "\code{eqp}" stands for dynamic slicing scheme with \eqn{n^{1/2}}-resolution (for \emph{K}-sample test, \eqn{K > 1}) or \eqn{n}-resolution (for one-sample test).}
  \item{lambda}{Penalty for introducing an additional slice, which is used to avoid making too many slices. It corresponds to the type I error under the scenario that the two variables are independent. \code{lambda} should be greater than 0.}
  \item{alpha}{Penalty required for "\code{ds}" type in one-sample test. It penalizes both the width and the number of slices to avoid too many slices and degenerate slice (interval). \code{alpha} should be greater than 1.}
  \item{rounds}{Number of permutations for estimating empirical \emph{p}-value.}
}
\details{
  If \code{x} is an integer vector, \code{ds_test} performs \emph{K}-sample test (\eqn{K > 1}).
  
  Under this scenario, suppose that there are observations \code{y} drawn from some \emph{continuous} populations. Let \code{x} be a vector that stores values of indicator of samples from different populations, \emph{i.e.}, \code{x} has values \eqn{0, 1, \ldots, K-1}. The null hypothesis is that these populations have the same distribution.
  
  If \code{x} is a character string naming a continuous (cumulative) distribution function, \code{ds_test} performs one-sample test with the null hypothesis that the distribution function which generated \code{y} is distribution \code{x} with parameters specified by \eqn{\ldots}. The parameters specified in \eqn{\ldots} must be pre-specified and not estimated from the data.
  
  Only empirical \emph{p}-values are available by specifying the value of parameter \code{rounds}, the number of permutation. \code{lambda} and \code{alpha} (for one-sample test with type "\code{ds}") contributes to \emph{p}-value.
  
  The procedure of choosing parameter \code{lambda} was described in Jiang, Ye & Liu (2015). Refer to \url{http://www.people.fas.harvard.edu/~junliu/DS/lambda-table.html} for the empirical relationship of \code{lambda}, sample size and type I error.
}
\value{
  A list with class "\code{htest}" containing the following components:
  \item{statistic}{The value of the dynamic slicing statistic.}
  \item{p.value}{The \emph{p}-value of the test.}
  \item{alternative}{A character string describing the alternative hypothesis.}
  \item{method}{A character string indicating what type of test was performed.}
  \item{data.name}{A character string giving the name(s) of the data.}
  \item{slices}{Slicing strategy that maximize dynamic slicing statistic in \emph{K}-sample test. Each row stands for a slice. Each column except the last one stands for the number of observations take each value in each slice. The last column is the number of observations in each slice \emph{i.e.}, the sum of the first column to the \emph{k}th column.}
}
\references{
  Jiang, B., Ye, C. and Liu, J.S. Non-parametric \emph{K}-sample tests via dynamic slicing. \emph{Journal of the American Statistical Association}, 110(510): 642-653, 2015.
}
\examples{
##  One-sample test
n <- 100
mu <- 0.5
y <- rnorm(n, mu, 1)
lambda <- 1.0
alpha <- 1.0
dsres <- ds_test(y, "pnorm", 0, 1, lambda = 1, alpha = 1, rounds = 100)
dsres <- ds_test(y, "pnorm", 0, 1, type = "ds", lambda = 1, alpha = 1)
dsres <- ds_test(y, "pnorm", 0, 1, type = "eqp", lambda = 1, rounds = 100)
dsres <- ds_test(y, "pnorm", 0, 1, type = "eqp", lambda = 1)

##  K-sample test
n <- 100
mu <- 0.5
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))

##  generate x in this way:
x <- c(rep(0, n), rep(1, n))
x <- as.integer(x)

##  or in this way:
x <- c(rep("G1", n), rep("G2", n))
x <- relabel(x)

lambda <- 1.0
dsres <- ds_test(y, x, lambda = 1, rounds = 100)
dsres <- ds_test(y, x, type = "eqp", lambda = 1, rounds = 100)
}
