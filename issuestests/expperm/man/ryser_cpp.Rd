\name{ryser_cpp}
\alias{ryser_cpp}
\title{The Ryser method for computing an expected permutation matrix using C++}
\usage{
ryser_cpp(A)
}
\arguments{
\item{A}{A matrix of assignment likelihoods.}
}
\value{
\code{E(P)}, the expected permutation matrix corresponding to \code{A}.
}
\description{
Computes the expected permutation matrix and marginal likelihood from a matrix of assignment likelihoods using the Ryser algorithm.
}
\examples{
data(A)
ryser_cpp(A)
}
