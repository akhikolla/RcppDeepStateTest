\name{midrq}
\alias{midrq.fit}
\alias{midrq}

\title{
Mid-Quantile Regression for Discrete Responses}
\description{
This function is used to fit a mid-quantile regression model when the response is discrete.
}
\usage{
midrq(formula, data, tau = 0.5, lambda = NULL, subset, weights, na.action,
	contrasts = NULL, offset, type = 1, midFit = NULL, control = list())
midrq.fit(x, y, offset, lambda, binary, midFit, type, tau, method)
}

\arguments{
  \item{formula}{
an object of class \code{\link{formula}}: a symbolic description of the model to be fitted.
}
  \item{data}{
an optional data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables in the model. If not found in data, the variables are taken from environment(formula), typically the environment from which \code{midrq} is called.
}
  \item{tau}{
quantile to be estimated. This can be a vector of quantiles in \code{midrq}, but must be one single quantile in \code{midrq.fit}.
}
  \item{lambda}{
a numerical value for the transformation parameter. This is provided by the user or set to \code{NULL}. The transformation is always Box-Cox, unless the response is binary (0-1) in which case the trasformation is Aranda-Ordaz. See \code{\link{bc}} and \code{\link{ao}}.
}
  \item{subset}{
an optional vector specifying a subset of observations to be used in the fitting process.
}
  \item{weights}{
an optional vector of weights to be used in the fitting process.
}
  \item{na.action}{
a function which indicates what should happen when the data contain \code{NA}s.
}
  \item{contrasts}{
an optional list. See the \code{contrasts.arg} of \code{\link{model.matrix.default}}.
}
  \item{offset}{
an optional offset to be included in the model frame. This must be provided in \code{midrq.fit} (e.g., a vector of zeros).
}
  \item{type}{
estimation method for the fitting process. See details.
}
  \item{midFit}{
\code{cmidecdf} object used for fitting conditional mid-quantiles. If set to \code{NULL} in \code{midrq}, it is automatically created. It must be provided in \code{midrq.fit}.
}
  \item{control}{
list of control parameters of the fitting process. See \code{\link{midrqControl}}.
}

  \item{x}{
design matrix of dimension \eqn{n * p}.
}
  \item{y}{
vector of observations of length \eqn{n}.
}

  \item{binary}{
logical flag. Is the response binary?
}

\item{method}{
	character vector that specifies the optimization algorithm in \code{\link{optim}} to fit a conditional mid-quantile model when \code{type = 1} or \code{type = 2}. Only \code{"Nelder-Mead"} has been tested.
}

}

\details{A linear mid-quantile regression model is fitted to the transformed response. The transformation of the response can be changed with the argument \code{lambda}. If \code{lambda = NULL}, then no transformation is applied (i.e., identity); if \code{lambda} is a numeric value, then the Box-Cox transformation is applied (e.g., 0 for log-transformation). However, \code{midrq} will automatically detect whether the response is binary, in which case the Aranda-Ordaz transformation is applied. In contrast, the user must declare whether the response is binary in \code{midrq.fit}.

There are 3 different estimators. \code{type = 1} is based on a general-purpose estimator (i.e., \code{\link{optim}}). \code{type = 2} is similar to \code{type = 1}, except the loss function is averaged over the space of the predictors (i.e., CUSUM). \code{type = 3} is the least-squares estimator discussed by Geraci and Farcomeni (2019).} 

\value{
a list of class \code{midrq} containing the following components

\item{call}{the matched call.}
\item{x}{the model matrix.}
\item{y}{the model response.}
\item{hy}{the tranformed model response.}
\item{tau}{the order of the estimated quantile(s).}
\item{coefficients}{regression quantile (on the log--scale).}
\item{fitted.values}{fitted values (on the response scale).}
\item{offset}{offset.}
\item{terms}{the terms object used.}
\item{term.labels}{names of coefficients.}
}


\references{
Geraci, M. and A. Farcomeni. Mid-quantile regression for discrete responses. arXiv:1907.01945 [stat.ME]. URL: \url{https://arxiv.org/abs/1907.01945/}.
}

\author{
Marco Geraci with contributions from Alessio Farcomeni
}



\examples{

\dontrun{
# Esterase data
data(esterase)

# Fit quantiles 0.25 and 0.75
fit <- midrq(Count ~ Esterase, tau = c(0.25, 0.75), data = esterase, type = 3, lambda = 0)
coef(fit)

# Plot
with(esterase, plot(Count ~ Esterase))
lines(esterase$Esterase, fit$fitted.values[,1], col = "blue")
lines(esterase$Esterase, fit$fitted.values[,2], col = "red")
legend(8, 1000, lty = c(1,1), col = c("blue", "red"), legend = c("tau = 0.25","tau = 0.75"))

}

}

\seealso{
\code{\link{residuals.midrq}}, \code{\link{predict.midrq}}, \code{\link{coef.midrq}} 
}

\keyword{conditional quantiles}
\keyword{discrete}
