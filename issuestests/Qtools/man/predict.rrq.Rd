\name{predict.rrq}
\alias{predict.rrq}

\title{
Predictions from Restricted Quantile Regression Models
}

\description{
This function computes predictions based on fitted restricted quantile regression models.
}

\usage{
\method{predict}{rrq}(object, newdata, na.action = na.pass, ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{rrq}.
}
  \item{newdata}{
an optional data frame in which to look for variables with which to predict. If omitted, the fitted values are used.
}
  \item{na.action}{
function determining what should be done with missing values in \code{newdata}. The default is to predict \code{NA}.
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


\keyword{ predict }

