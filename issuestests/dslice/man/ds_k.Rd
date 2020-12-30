\name{ds_k}
\alias{ds_k}
\docType{package}
\title{
  Dependency detection between level \eqn{k} (\eqn{k > 1}) categorical variable and continuous variable
}
\description{
  Dependency detection between level \eqn{k} (\eqn{k > 1}) categorical variable and continuous variable. The basic idea is that the different values of categorical variable correspond to different distribution of continuous variable if there exist dependency between this two varibles, otherwise the distributions of continuous variable do not show difference conditioning on the values of categorical variable. Statistic for this dynamic slicing method is a regularized likelihood-ratio calculated via a dynamic programming procedure. For more details please refer to Jiang, Ye & Liu (2015). Results contains value of dynamic slicing statistic and slicing strategy. It could be applied for non-parametric \emph{K}-sample hypothesis testing.
}
\usage{
  ds_k(x, xdim, lambda, slice = FALSE)	
}
\arguments{
  \item{x}{Vector: observations of categorical variable, \eqn{0,1,\ldots,k-1} for level \eqn{k} categorical variable, should be ranked according to values of continuous variable in advanced, either ascending or descending.}
  \item{xdim}{Level of \code{x}, equals \eqn{k}.}
  \item{lambda}{Penalty for introducing an additional slice, which is used to avoid making too many slices. It corresponds to the type I error under the scenario that the two variables are independent. \code{lambda} should be greater than 0.}
  \item{slice}{Indicator for reporting slicing strategy or not.}
}
\value{
  \item{dsval}{Value of dynamic slicing statistic. It is nonnegative. If it equals zero, the categorical variable and continuous variable will be treated as independent of each other, otherwise they will be treated as dependent.}
  \item{slices}{Slicing strategy that maximize dynamic slicing statistic based on currently ranked vector \code{x}. It will be reported if \code{slice} is true. Each row stands for a slice. Each column except the last one stands for the number of observations take each value in each slice. The last column is the number of observations in each slice \emph{i.e.}, the sum of the first column to the \emph{k}th column.}
}
\seealso{
  \code{\link{ds_eqp_k}}.
}
\references{
  Jiang, B., Ye, C. and Liu, J.S. Non-parametric \emph{K}-sample tests via dynamic slicing. \emph{Journal of the American Statistical Association}, 110(510): 642-653, 2015.
}
\examples{
n <- 100
mu <- 0.5
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))
x <- c(rep("1", n), rep("2", n))
x <- relabel(x)
x <- x[order(y)]
xdim <- max(x) + 1
lambda <- 1.0
dsres <- ds_k(x, xdim, lambda, slice = TRUE)
}
