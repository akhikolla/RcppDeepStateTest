\name{nlControl}
\alias{nlControl}

\title{
Control parameters for gradient search estimation
}
\description{
A list of parameters for controlling the fitting process.
}
\usage{
nlControl(tol_ll = 1e-05, tol_theta = 0.001, check_theta = FALSE,
	step = NULL, beta = 0.5, gamma = 1.25, reset_step = FALSE,
	maxit = 1000, smooth = FALSE, omicron = 0.001, verbose = FALSE)
}

\arguments{
  \item{tol_ll}{
tolerance expressed as relative change of the objective function.
}
  \item{tol_theta}{
tolerance expressed as relative change of the estimates.
}
  \item{check_theta}{
logical flag. If \code{TRUE} the algorithm performs a check on the change in the estimates in addition to the likelihood.
}
  \item{step}{
step size (default standard deviation of response).
}

  \item{beta}{
decreasing step factor for line search (0,1).
}

  \item{gamma}{
nondecreasing step factor for line search (>= 1).
}

 \item{reset_step}{
logical flag. If \code{TRUE} the step size is re-setted to the initial value at each iteration.
}

  \item{maxit}{
maximum number of iterations.
}

  \item{smooth}{
logical flag. If \code{TRUE} the standard loss function is replaced with a smooth approximation.
}

  \item{omicron}{
small constant for smoothing the loss function when using \code{smooth = TRUE}. See details.
}
  \item{verbose}{
logical flag.
}
}

\value{
a list of control parameters.

}

\details{
The optimization algorithm is along the lines of the gradient search algorithm (Bottai et al, 2015). If \code{smooth = TRUE}, the classical non-differentiable loss function is replaced with a smooth version (Chen and Wei, 2005).
}

\references{
Bottai M, Orsini N, Geraci M (2015). A Gradient Search Maximization Algorithm for the Asymmetric Laplace Likelihood, Journal of Statistical Computation and Simulation, 85(10), 1919-1925.

Chen C, Wei Y (2005). Computational issues for quantile regression. Sankhya: The Indian Journal of Statistics, 67(2), 399-417.
}

\author{
Marco Geraci}

\seealso{
\code{\link{nlrq1}}
}

\keyword{fitting}
\keyword{control}
