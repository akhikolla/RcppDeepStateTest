% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/ChangePointTests.R
\name{andrews_test_reg}
\alias{andrews_test_reg}
\title{Multivariate Andrews' Test for End-of-Sample Structural Change}
\usage{
andrews_test_reg(formula, data, M, pval = TRUE, stat = TRUE)
}
\arguments{
\item{formula}{The regression formula, which will be passed to
\code{\link[stats]{lm}}}

\item{data}{\code{data.frame} containing the data}

\item{M}{Numeric index of the location of the first potential change point}

\item{pval}{If \code{TRUE}, return a p-value}

\item{stat}{If \code{TRUE}, return a test statistic}
}
\value{
If both \code{pval} and \code{stat} are \code{TRUE}, a list
        containing both; otherwise, a number for one or the other, depending
        on which is \code{TRUE}
}
\description{
This implements Andrews' test for end-of-sample change, as described by
\insertCite{andrews03;textual}{CPAT}. This test was derived for detecting a
change in multivarate data, aso originally described. See
\insertCite{andrews03}{CPAT} for a description of the test.
}
\examples{
x <- rnorm(1000)
y <- 1 + 2 * x + rnorm(1000)
df <- data.frame(x, y)
CPAT:::andrews_test_reg(y ~ x, data = df, M = 900)
}
\references{
\insertAllCited{}
}
