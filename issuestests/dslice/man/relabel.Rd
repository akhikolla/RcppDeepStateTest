\name{relabel}
\alias{relabel}
\title{
  Reassigning values of categorical variable
}
\description{
  Reassigning values of categorical variable. It is used for generating legal value of categorical variable before applying dynamic slicing.
}
\usage{
  relabel(x)
}
\arguments{
  \item{x}{A vector of data values.}
}
\value{
  An integer vector with values range from 0 to k (k > 0).
}
\seealso{
  \code{\link{ds_test}}.
}
\examples{
n <- 10
x <- c(rep("G1", n), rep("G2", n))
x <- relabel(x)

x <- c(rep(4, n), rep(5, n), rep(NA, n))
x <- relabel(x)
}