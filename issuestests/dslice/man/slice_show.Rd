\name{slice_show}
\alias{slice_show}
\title{
  Show the slicing result
}
\description{
  Showing slicing result and plotting counts of observations in each slice.
}
\usage{
  slice_show(slices_obj, main="Counts in each slice", xlab="Slices", ylab="Percentage")
}
\arguments{
  \item{slices_obj}{A matrix stores slicing strategy. It is a component of object returned by function \code{dslice_k} or \code{dslice_eqp_k}.}
  \item{main}{An overall title for the plo}
  \item{xlab}{A title for the x axis}
  \item{ylab}{A title for the y axis}
}
\value{
  A ``ggplot'' object which illustrates details of slicing.
}
\seealso{
  \code{\link{ds_k}}, \code{\link{ds_eqp_k}}.
}
\examples{
n <- 100
mu <- 0.5
y <- c(rnorm(n, -mu, 1), rnorm(n, mu, 1))
x <- c(rep(0, n), rep(1, n))
x <- x[order(y)]
xdim <- max(x) + 1
lambda <- 1.0
dsres <- ds_k(x, xdim, lambda, slice = TRUE)

ds_show <- slice_show(dsres$slices)
}

