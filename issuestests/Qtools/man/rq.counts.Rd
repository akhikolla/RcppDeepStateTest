\name{rq.counts}
\alias{rq.counts}

\title{
Quantile Regression for Counts}
\description{
This function is used to fit a (log-linear) quantile regression model when the response is a count variable.
}
\usage{
rq.counts(formula, data = sys.frame(sys.parent()), tau = 0.5, subset, weights,
	na.action, contrasts = NULL, offset = NULL, method = "fn", M = 50,
	zeta = 1e-5, B = 0.999, cn = NULL, alpha = 0.05)
}

\arguments{
  \item{formula}{
an object of class \code{\link{formula}}: a symbolic description of the model to be fitted.
}
  \item{data}{
an optional data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables in the model. If not found in data, the variables are taken from environment(formula), typically the environment from which \code{rq.counts} is called.
}
  \item{tau}{
quantile to be estimated.
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
an optional offset to be included in the model frame.  
}
  \item{method}{
estimation method for the fitting process. See \code{\link{rq}}.
}

  \item{M}{
number of dithered samples.
}
  \item{zeta}{
small constant (see References).
}
  \item{B}{
right boundary for uniform random noise U[0,B] to be added to the response variable (see References).
}
 \item{cn}{
small constant to be passed to \code{Fn} (see Theorem 3, Machado and Santos Silva).
}

 \item{alpha}{
significance level.
}

}

\details{A linear quantile regression model is fitted to the log--transformed response. The notation used here follows closely that of Machado and Santos Silva (2005). This function is based on routines from package \code{quantreg} (Koenker, 2016). See also \code{lqm.counts} from package \code{lqmm} (Geraci, 2014) for Laplace gradient estimation.

As of version 1.4, the transformation of the response cannot be changed. This option may be reinstated in future versions.
} 

\value{
a list of class \code{rq.counts} containing the following components

\item{call}{the matched call.}
\item{method}{the fitting algorithm for \code{rq}.}
\item{x}{the model matrix.}
\item{y}{the model response.}
\item{tau}{the order of the estimated quantile(s).}
\item{tsf}{tranformation used (see also \code{attributes(tsf)}).}
\item{coefficients}{regression quantile (on the log--scale).}
\item{fitted.values}{fitted values (on the response scale).}
\item{tTable}{coefficients, standard errors, etc.}
\item{offset}{offset.}
\item{M}{specified number of dithered samples for standard error estimation.}
\item{Mn}{actual number of dithered samples used for standard error estimation that gave an invertible D matrix (Machado and Santos Silva, 2005).}
\item{InitialPar}{starting values for coefficients.}
\item{terms}{the terms object used.}
\item{term.labels}{names of coefficients.}
\item{rdf}{the number of residual degrees of freedom.}
}


\references{

Geraci M. Linear quantile mixed models: The lqmm package for Laplace quantile regression. Journal of Statistical Software. 2014;57(13):1-29.

Geraci M and Jones MC. Improved transformation-based quantile regression. Canadian Journal of Statistics 2015;43(1):118-132.

Koenker R. quantreg: Quantile Regression. 2016. R package version 5.29.

Machado JAF, Santos Silva JMC. Quantiles for counts. Journal of the American Statistical Association. 2005;100(472):1226-37.
}

\author{
Marco Geraci
}



\examples{

# Esterase data
data(esterase)

# Fit quantiles 0.25 and 0.75
fit1 <- rq.counts(Count ~ Esterase, tau = 0.25, data = esterase, M = 50)
coef(fit1)
fit2 <- rq.counts(Count ~ Esterase, tau = 0.75, data = esterase, M = 50)
coef(fit2)

# Plot
with(esterase, plot(Count ~ Esterase))
lines(esterase$Esterase, fit1$fitted.values, col = "blue")
lines(esterase$Esterase, fit2$fitted.values, col = "red")
legend(8, 1000, lty = c(1,1), col = c("blue", "red"), legend = c("tau = 0.25","tau = 0.75"))

}

\seealso{
\code{\link{residuals.rq.counts}}, \code{\link{predict.rq.counts}}, \code{\link{coef.rq.counts}}, \code{\link{maref.rq.counts}}
}

\keyword{conditional quantiles}
\keyword{discrete}
