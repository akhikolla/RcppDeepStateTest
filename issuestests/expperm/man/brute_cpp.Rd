\name{brute_cpp}
\alias{brute_cpp}
\title{Brute-force calculation of an expected permutation matrix using C++}
\usage{
brute_cpp(A)
}
\arguments{
\item{A}{A matrix of assignment likelihoods.}
}
\value{
\code{E(P)}, the expected permutation matrix corresponding to \code{A}.
}
\description{
Computes an expected permutation matrix and marginal likelihood from a matrix of assignment likelihoods. The function literally enumerates all permutations so will be impractial for matrices with more than 10 rows.
}
\examples{
data(A)
brute_cpp(A)
}
