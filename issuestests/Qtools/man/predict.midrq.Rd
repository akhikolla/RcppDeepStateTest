\name{predict.midrq}
\alias{predict.midrq}

\title{
Predictions from Mid-Quantile Regression Models
}

\description{
This function computes predictions based on fitted mid-quantile regression models.
}

\usage{
\method{predict}{midrq}(object, newdata, offset, na.action = na.pass,
	type = "response", ...)
}

\arguments{
  \item{object}{
	an object of \code{\link{class}} \code{midrq}.
	}

  \item{newdata}{
	an optional data frame in which to look for variables with which to predict. If omitted, the fitted values are used.
	}

  \item{offset}{
	an optional offset to be included in the model frame (when \code{newdata} is provided).
	}
  
  \item{na.action}{
	function determining what should be done with missing values in \code{newdata}. The default is to predict \code{NA}.
	}

 \item{type}{
	the type of prediction required. The default \code{"response"} is on the scale of the response variable, i.e. the values are back-transformed using the inverse of the transformation \eqn{h^{-1}(Xb)}; the alternative \code{"link"} is on the scale of the linear predictors \eqn{h(y) = Xb}.
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
\code{\link{residuals.midrq}}, \code{\link{midrq}}, \code{\link{coef.midrq}}
}

\keyword{predict}

