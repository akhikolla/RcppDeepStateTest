\name{cmidecdf}
\alias{cmidecdf.fit}
\alias{cmidecdf}

\title{
Mid-distribution Functions
}

\description{
Compute conditional mid-cumulative probabilities
}

\usage{
cmidecdf(formula, data, ecdf_est = "npc", npc_args = list(),
	theta = NULL, subset, weights, na.action,
	contrasts = NULL)
cmidecdf.fit(x, y, intercept, ecdf_est, npc_args = list(),
	theta = NULL)
}

\arguments{
  \item{formula}{
an object of class "\code{\link{formula}}" (or one that can be coerced to that class): a symbolic description of the model to be fitted. The details of model specification are given under `Details'.
}
  \item{data}{
an optional data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables in the model. By default the variables are taken from the environment from which the call is made.
}
  \item{ecdf_est}{
estimator of the (standard) conditional cumulative distribution. The options are: \code{npc} (default) for kernel estimator (Li and Racine, 2008); \code{logit}, \code{probit}, \code{cloglog} for binomial regression; \code{ao} for Aranda-Ordaz binomial regression.
}
  \item{npc_args}{
	named list of arguments for \code{\link{npcdistbw}} when \code{ecdf_est = npc}.
}
  \item{theta}{
values of the Aranda-Ordaz transformation parameter for grid search when \code{ecdf_est = "ao"}.
}
  \item{subset}{
an optional vector specifying a subset of observations to be used in the fitting process.
}
  \item{weights}{
an optional vector of weights to be used in the fitting process. Not currently implemented.
}
  \item{na.action}{
a function which indicates what should happen when the data contain \code{NA}s.
}
  \item{contrasts}{
an optional list. See the contrasts.arg of \code{\link{model.matrix.default}}.
}
  \item{x}{
design matrix of dimension \eqn{n * p}.
}
  \item{y}{
vector of observations of length \eqn{n}.
}
  \item{intercept}{
logical flag. Does \code{x} include a vector of ones?
}

}

\value{
An object of class \code{\link{class}} \code{cmidecdf} with mid-cumulative probabilities. This is a list that contains:

\item{G}{Estimated conditional mid-probabilities. This is a \eqn{n * k} matrix, where \eqn{n} is the sample size and \eqn{k} is the number of unique values of \code{y}.}
\item{Fhat}{Estimated (standard) cumulative probabilities.}
\item{Fse}{Standard error for Fhat.}
\item{yo}{unique values of \code{y}.}
\item{bw}{\code{npcdistbw} object.}
\item{ecdf_est}{estimator used.}

}

\references{
Geraci, M. and A. Farcomeni. Mid-quantile regression for discrete responses. arXiv:1907.01945 [stat.ME]. URL: \url{https://arxiv.org/abs/1907.01945/}.

Li, Q. and J. S. Racine (2008). Nonparametric estimation of conditional cdf and quantile functions with mixed categorical and continuous data. Journal of Business and Economic Statistics 26(4), 423-434.

Peracchi, F. (2002). On estimating conditional quantiles and distribution functions. Computational Statistics and Data Analysis 38(4), 433-447.
}

\author{
Marco Geraci with contributions from Alessio Farcomeni
}

\examples{

\dontrun{
n <- 100
x <- rnorm(n, 0, 3)
y <- floor(1 + 2*x) + sample(1:5, n, replace = TRUE)
cmidecdf(y ~ x, ecdf_est = "logit")
}

}

\seealso{
\code{\link{midecdf}}
}


\keyword{ conditional quantiles }
