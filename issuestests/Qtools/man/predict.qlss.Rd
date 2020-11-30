\name{predict.qlss}
\alias{predict.qlss}

\title{
Predictions from Conditional LSS Objects
}

\description{
This function computes predictions based on fitted conditional QLSS objects.
}

\usage{
\method{predict}{qlss}(object, newdata, interval = FALSE, level = 0.95, R = 200,
	na.action = na.pass, trim = 0.05, ...)
}

\arguments{
  \item{object}{
an object as returned by \code{\link{qlss.formula}}.
}

  \item{newdata}{
an optional data frame in which to look for variables with which to predict. If omitted, the fitted values are used.
}

  \item{interval}{
logical flag. If \code{TRUE}, confidence intervals for predictions are computed by bootstrap.
}

 \item{level}{
nominal coverage level of the confidence interval.
}

 \item{R}{
number of bootstrap replications used to compute confidence intervals.
}

  \item{na.action}{
function determining what should be done with missing values in \code{newdata}. The default is to predict \code{NA}.
}

  \item{trim}{
proportion of extreme bootstrap replications to be trimmed before standard errors are computed.
}

 \item{\dots}{
not used.
}
}

\author{
Marco Geraci
}

\examples{

\dontrun{
# Fit QLSS object
trees2 <- trees[order(trees$Height),]
fit <- qlss(Volume ~ Height, data = trees2)

## Predict using newdata. Calculate confidence intervals using 200 bootstrap replications
# large confidence intervals for shape index due to small IQR at low values of height
#xx <- seq(min(trees2$Height), max(trees2$Height), length = 100)
#new <- data.frame(Height = xx)
#set.seed(121)
#fit.pred <- predict(fit, newdata = new, interval = TRUE, level = 0.95, R = 200)
#plot(fit.pred, z = xx, interval = TRUE, xlab = "height")

# Restrict range for Height

xx <- seq(65, 87, length = 100)
new <- data.frame(Height = xx)
set.seed(121)
fit.pred <- predict(fit, newdata = new, interval = TRUE, level = 0.95, R = 200)
plot(fit.pred, z = xx, interval = TRUE, xlab = "height") # better

}
}

\seealso{
\code{\link{qlss.formula}}
}

\keyword{predict}

