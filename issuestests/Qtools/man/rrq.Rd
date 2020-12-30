\name{rrq}
\alias{rrq.fit}
\alias{rrq.wfit}
\alias{rrq}

\title{
Restricted Regression Quantiles
}
\description{
This function fits a restricted quantile regression model to avoid crossing of quantile curves.
}

\usage{
rrq(formula, tau, data, subset, weights, na.action, method = "fn",
model = TRUE, contrasts = NULL, ...)
rrq.fit(x, y, tau, method = "fn", ...)
rrq.wfit(x, y, tau, weights, method = "fn", ...)
}

\arguments{
  \item{formula}{
a formula object, with the response on the left of a \code{~} operator, and the terms, separated by \code{+} operators, on the right.
}
  \item{x}{
the design matrix.
}
  \item{y}{
the response variable.
}
  \item{tau}{
the quantile(s) to be estimated.
}
  \item{data}{
a data frame in which to interpret the variables named in the formula.
}
  \item{subset}{
an optional vector specifying a subset of observations to be used in the fitting process.
}
  \item{weights}{
an optional vector of weights to be used in the fitting process. Should be NULL or a numeric vector. 
}
  \item{na.action}{
a function which indicates what should happen when the data contain \code{NA}s.
}
  \item{method}{
the algorithm used to compute the fit (see \code{\link{rq}}).
}
  \item{model}{
if \code{TRUE} then the model frame is returned. This is essential if one wants to call summary subsequently.
}
  \item{contrasts}{
a list giving contrasts for some or all of the factors default = NULL appearing in the model formula. The elements of the list should have the same name as the variable and should be either a contrast matrix (specifically, any full-rank matrix with as many rows as there are levels in the factor), or else a function to compute such a matrix given the number of levels.
}
  \item{\dots}{
optional arguments passed to \code{rq.fit} or \code{rq.wfit}.
}

}

\references{
He X. Quantile curves without crossing. The American Statistician 1997;51(2):186-192.

Koenker R. quantreg: Quantile Regression. 2016. R package version 5.29.
}

\author{
Marco Geraci
}

\examples{
data(esterase)

# Fit standard quantile regression
fit <- quantreg::rq(Count ~ Esterase, data = esterase, tau = c(.1,.25,.5,.75,.9))
yhat <- fit$fitted.values

# Fit restricted quantile regression
fitr <- rrq(Count ~ Esterase, data = esterase, tau = c(.1,.25,.5,.75,.9))
yhat2 <- predict(fitr)


# Plot results
par(mfrow = c(1, 2))

# Plot regression quantiles
with(esterase, plot(Count ~ Esterase, pch = 16, cex = .8))
apply(yhat, 2, function(y,x) lines(x,y,lwd = 1.5), x = esterase$Esterase)

# Plot restricted regression quantiles
with(esterase, plot(Count ~ Esterase, pch = 16, cex = .8))
apply(yhat2, 2, function(y,x) lines(x,y,lwd = 1.5), x = esterase$Esterase)

}

\keyword{ quantile crossing }
\keyword{ conditional quantiles }

