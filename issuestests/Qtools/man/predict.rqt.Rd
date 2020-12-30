\name{predict.rqt}
\alias{predict.rqt}

\title{
Predictions from Quantile Regression Transformation Models
}

\description{
This function computes predictions based on fitted quantile regression transformation models.
}

\usage{
\method{predict}{rqt}(object, newdata, na.action = na.pass,
type = "response", namevec = NULL, ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{rqt}.
}

  \item{newdata}{
an optional data frame in which to look for variables with which to predict. If omitted, the fitted values are used.
}

  \item{na.action}{
function determining what should be done with missing values in \code{newdata}. The default is to predict \code{NA}.
}

 \item{type}{
the type of prediction required. The default \code{"response"} is on the scale of the response variable, i.e. the values are back-transformed using the inverse of the transformation \eqn{h^{-1}(Xb)}; the alternative \code{"link"} is on the scale of the linear predictors \eqn{h(y) = Xb}; finally, predictions for marginal effects are given with \code{"maref"}.
}
 \item{namevec}{
character giving the name of the covariate with respect to which the marginal effect is to be computed. If \code{type = "maref"}, this argument is required. See \code{\link{maref.rqt}}.
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


\seealso{
\code{\link{residuals.rqt}}, \code{\link{tsrq}}, \code{\link{coef.rqt}}, \code{\link{maref.rqt}}
}

\keyword{predict}

