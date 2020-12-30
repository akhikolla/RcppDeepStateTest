\name{sink_cpp}
\alias{sink_cpp}
\title{A variational approximation of an expected permutation matrix using C++}
\usage{
sink_cpp(A, maxit = 99)
}
\arguments{
\item{A}{A matrix of assignment likelihoods.}

\item{maxit}{An integer specifying the maximum number of steps used in the optimization.}
}
\value{
\code{E(P)}, the expected permutation matrix corresponding to \code{A}.
}
\description{
Computes an approximate expected permutation matrix and marginal likelihood from a matrix of assignment likelihoods. The approximation minimizes a constrained KL divergence from the likelihood, and is computed via the repeated renormalization of the input's rows and columns.
}
\examples{
data(A)
sink_cpp(A)
}
