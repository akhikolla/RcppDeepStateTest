\name{BG_cpp}
\alias{BG_cpp}
\title{The Brualdi-Gibson method for computing an expected permutation matrix using C++}
\usage{
BG_cpp(A)
}
\arguments{
\item{A}{A tridiagonal matrix of assignment likelihoods.}
}
\value{
\code{E(P)}, the expected permutation matrix corresponding to \code{A}.
}
\description{
Computes the expected permutation matrix and marginal likelihood from a tridiagonal matrix of assignment likelihoods using the Brualdi-Gibson method.
}
\examples{
data(triA)
BG_cpp(triA)
}
