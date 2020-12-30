\name{predict.rq.counts}
\alias{predict.rq.counts}

\title{
Predictions from rq.counts Objects
}

\description{
This function computes predictions based on fitted linear quantile models.
}

\usage{
\method{predict}{rq.counts}(object, newdata, offset,
	na.action = na.pass, type = "response",
	namevec = NULL, ...)
}

\arguments{
  \item{object}{
an \code{rq.counts} object.
}
  \item{newdata}{
an optional data frame in which to look for variables with which to predict. If omitted, the fitted values are used.
}
  \item{offset}{
an offset to be used with \code{newdata}.
}
 \item{na.action}{
function determining what should be done with missing values in \code{newdata}. The default is to predict \code{NA}.}

 \item{type}{
the type of prediction required. The default \code{"response"} is on the scale of the response variable, i.e. the values are back-transformed using the inverse of the transformation \eqn{h^{-1}(Xb)}; the alternative \code{"link"} is on the scale of the linear predictors \eqn{h(y) = Xb}; finally, predictions for marginal effects are given with \code{"maref"}.
}
 \item{namevec}{
character giving the name of the covariate with respect to which the marginal effect is to be computed. If \code{type = "maref"}, this argument is required. See \code{\link{maref.rq.counts}}.
}
  \item{\dots}{
not used.
}

}

\value{
a vector or a matrix or an array of predictions.
}


\author{
Marco Geraci
}

\examples{

# Esterase data
data(esterase)

# Fit quantiles 0.25 and 0.75
fit <- rq.counts(Count ~ Esterase, tau = 0.5, data = esterase, M = 50)
cbind(fit$fitted.values, predict(fit, type = "response"))

}


\seealso{
\code{\link{residuals.rq.counts}}, \code{\link{rq.counts}}, \code{\link{coef.rq.counts}}, \code{\link{maref.rq.counts}}
}

\keyword{predict}
