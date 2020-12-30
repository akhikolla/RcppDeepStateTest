\name{bfslice_c}
\alias{bfslice_c}
\docType{package}
\title{
  Dependency and conditional dependency detection between a level \eqn{k} (\eqn{k > 1}) categorical variable and a continuous variable via Bayes factor.
}
\description{ 
  Conditional dependency detection between a level \eqn{k_x} (\eqn{k_x > 1}) categorical variable \code{x} and a continuous variable \code{y} via Bayes factor given a level \eqn{k_z} categorical variable \code{z}. If \eqn{k_z = 1}, it is unconditional dependency detection method. It could be applied for non-parametric variable selecltion.
}
\usage{
  bfslice_c(z, x, zdim, xdim, lambda, alpha)
}
\arguments{
  \item{z}{Vector: observations of given (preselected) categorical variable, \eqn{0,1,\ldots,k_z-1} for level \eqn{k_z} categorical variable, should be ranked according to values of continuous variable \code{y} with \code{x} in advanced, either ascending or descending.}
  \item{x}{Vector: observations of categorical variable, \eqn{0,1,\ldots,k_x-1} for level \eqn{k_x} categorical variable, should be ranked according to values of continuous variable \code{y} with \code{z} in advanced, either ascending or descending.}
  \item{zdim}{Level of \code{z}, equals \eqn{k_z}.}
  \item{xdim}{Level of \code{x}, equals \eqn{k_x}.}  
  \item{lambda}{\code{lambda} corresponds to the probability that makes slice in each possible position. \code{lambda} should be greater than 0.}
  \item{alpha}{\code{alpha} is hyper-parameter of the prior distribution of frequency in each slice. \code{alpha} should be greater than 0 and less equal than \eqn{k_x}.}
}
\value{
  Value of Bayes factor (nonnegative). Bayes factor could be treated as a statistic and one can take some threshold then calculates the corresponded Type I error rate. One can also take the value of Bayes factor for judgement.
}
\seealso{
  \code{\link{bfslice_u}, \link{bfslice_eqp_c}}.
}
\references{
  Jiang, B., Ye, C. and Liu, J.S. Bayesian nonparametric tests via sliced inverse modeling. \emph{Bayesian Analysis}, 12(1): 89-112, 2017.
}
\examples{
n <- 100
mu <- 0.5

## Unconditional test
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))
x <- c(rep(0, n), rep(1, n))
z <- rep(0, 2*n)

## Conditional test
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))
x <- c(rep(0, n/5), rep(1, n), rep(0, 4*n/5))
z <- c(rep(0, n), rep(1, n))
z <- z[order(y)]

x <- x[order(y)]
zdim <- max(z) + 1
xdim <- max(x) + 1
lambda <- 1.0
alpha <- 1.0
bfval <- bfslice_c(z, x, zdim, xdim, lambda, alpha)
}
