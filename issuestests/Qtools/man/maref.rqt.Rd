\name{maref.rqt}
\alias{maref}
\alias{maref.rq.counts}
\alias{maref.rqt}

\title{
Marginal Effects
}

\description{
This function computes marginal effects for \code{rqt} and \code{rq.counts} objects.
}

\usage{
maref(object, namevec)
\method{maref}{rqt}(object, namevec)
\method{maref}{rq.counts}(object, namevec)
}

\arguments{
  \item{object}{
an \code{rqt} or an \code{rq.counts} object.
}
  \item{namevec}{
character giving the name of the covariate with respect to which the marginal effect is to be computed.
}
}

\details{
Given the \eqn{\tau}th conditional quantile function \eqn{Q_{h(Y)|X}(\tau) = \eta = Xb}, where \eqn{Y} is the response variable, \eqn{X} a design matrix, and \eqn{h} is a one-parameter transformation with inverse \eqn{h^{-1} = g}, \code{maref} computes the marginal effect:
\deqn{
\frac{dQ_{Y|X}(\tau)}{dx_{j}} = \frac{dg\{Q_{h(Y)|X}(\tau)\}}{dx_{j}}
}{dQ(\tau)/dx_{j} = dg(Q_{h(Y)})/dx_{j}}
where \eqn{x_{j}} is the \emph{j}-th covariate with respect to which the marginal effect is to be computed and its name is given in the argument \code{namevec}.

The derivative of the quantile function is the the product of two components
\deqn{\frac{dQ_{Y|X}(\tau)}{dx_{j}} = \frac{dg(\eta)}{d\eta} \cdot \frac{d\eta}{dx_{j}}
}{dQ(\tau)/dx_{j} = dg(\eta)/d\eta d\eta/dx_{j}}

The derivative w.r.t. the linear predictor \eqn{\eta} is calculated symbolically after parsing the \code{object}'s formula and is evaluated using the \code{object}'s model frame. The function that parses formulae has a limited scope. It recognizes interactions and basic operators (e.g., log, exp, etc.). Therefore, it is recommended to use simple expressions for the model's formula.

This function can be applied to models of class \code{rqt} and \code{rq.counts}. Note that marginal effects can be similarly obtained using \code{\link{predict.rqt}} or \code{\link{predict.rq.counts}} with argument \code{type = "maref"} which, in addition, allows for an optional data frame to be specified via \code{newdata}.
}


\value{
a vector for single quantiles or a matrix for multiple quantiles of marginal effects.
}


\author{
Marco Geraci
}

\examples{
\dontrun{
# Box-Cox quantile regression model (dataset trees from package 'datasets')
fit <- tsrq(Volume ~ Height, data = trees, tsf = "bc", tau = 0.9)

# Coefficients (transformed scale)
coef(fit)

# Design matrix
head(fit$x)

# Marginal effect of 'Height'
maref(fit, namevec = "Height")

# Predict marginal effects over grid of values for Height
nd <- data.frame(Height = seq(min(trees$Height), max(trees$Height), length = 100))
x <- predict(fit, newdata = nd, type = "maref", namevec = "Height")

# Plot
plot(nd$Height, x, xlab = "Height", ylab = "Marginal effect on volume")

# Include 'Girth' and interaction between 'Height' and 'Girth'
fit <- tsrq(Volume ~ Height * Girth, data = trees, tsf = "bc", tau = 0.5)
head(fit$x)

# Predict marginal effects over grid of values for Height (for fixed girth)
nd$Girth <- rep(mean(trees$Girth), 100)
x <- predict(fit, newdata = nd, type = "maref", namevec = "Height")
plot(nd$Height, x, xlab = "Height", ylab = "Marginal effect on volume")

# Quantile regression for counts (log transformation)
data(esterase)
fit <- rq.counts(Count ~ Esterase, tau = 0.25, data = esterase, M = 50)
maref(fit, namevec = "Esterase")
}
}


\seealso{
\code{\link{tsrq}}
}

\keyword{coefficients}
