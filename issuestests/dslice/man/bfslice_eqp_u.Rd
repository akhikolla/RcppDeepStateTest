\name{bfslice_eqp_u}
\alias{bfslice_eqp_u}
\docType{package}
\title{
  Dependency detection between a level \eqn{k} (\eqn{k > 1}) categorical variable and a continuous variable via Bayes factor with given size of each group.
}
\description{ 
  Dependency detection between a level \eqn{k} (\eqn{k > 1}) categorical variable \code{x} and a continuous variable \code{y} via Bayes factor with \eqn{O(n^{1/2})}-resolution. The basic idea is almost the same as \code{\link{bfslice_u}}. The only different is that \code{\link{bfslice_eqp_u}} groups samples into approximate \eqn{O(n^{1/2})} groups which contain approximate \eqn{O(n^{1/2})} samples and treat the groups as a sample to calculate Bayes facor.
}
\usage{
  bfslice_eqp_u(x, dim, lambda, alpha)
}
\arguments{
  \item{x}{Vector: observations of categorical variable, \eqn{0,1,\ldots,k-1} for level \eqn{k} categorical variable, should be ranked according to values of continuous variable \code{y}, either ascending or descending.}
  \item{dim}{Level of \code{x}, equals \eqn{k}.}  
  \item{lambda}{\code{lambda} corresponds to the probability that makes slice in each possible position. \code{lambda} should be greater than 0.}
  \item{alpha}{\code{alpha} is hyper-parameter of the prior distribution of frequency in each slice. \code{alpha} should be greater than 0 and less equal than \eqn{k}.}
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
n <- 1000
mu <- 0.2
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))
x <- c(rep(0, n), rep(1, n))
x <- x[order(y)]
dim <- max(x) + 1
lambda <- 1.0
alpha <- 1.0
bfval <- bfslice_eqp_u(x, dim, lambda, alpha)
}
