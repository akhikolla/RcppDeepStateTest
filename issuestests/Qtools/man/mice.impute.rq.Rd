\name{mice.impute.rq}
\alias{mice.impute.rrq}
\alias{mice.impute.rq}

\title{
QR-based Multiple Imputation
}

\description{
This function is used to multiply impute missing values using quantile regression imputation models.
}

\usage{
mice.impute.rq(y, ry, x, tsf = "none", symm = TRUE, dbounded = FALSE,
	lambda = NULL, x.r = NULL, par = NULL, conditional = TRUE,
	epsilon = 0.001, method.rq = "fn", ...)
mice.impute.rrq(y, ry, x, tsf = "none", symm = TRUE, dbounded = FALSE,
	lambda = NULL, epsilon = 0.001, method.rq = "fn", ...)
}

\arguments{
  \item{y}{
numeric vector of length \code{n} with \code{nmis} missing values.
}
  \item{ry}{
missing data indicator. Logical vector of length \code{n}: \code{FALSE} if \code{y} is missing, \code{TRUE} if \code{y} is observed.
}
  \item{x}{
matrix \code{n x p} of completely observed covariates.
}
  \item{tsf}{
transformation to be used. Possible options are \code{mcjI} for Proposal I, \code{bc} for Box-Cox and \code{ao} for Aranda-Ordaz transformation models. No transformation is used by default.
}
  \item{symm}{
logical flag. If \code{TRUE} (default) a symmetric transformation is used.
}
  \item{dbounded}{
logical flag. If \code{TRUE} the response \code{y} is assumed to be bounded between 0 and 1.
}
  \item{lambda}{
if \code{conditional = TRUE}, a numerical value for the transformation parameter. This is provided by the user or set to zero if not specified. If \code{conditional = FALSE}, this argument is ignored.
}
  \item{x.r}{
range of the mapping for doubly bounded variables.
}
  \item{par}{
if \code{conditional = FALSE}, starting values for \code{\link{nlrq1}} can be provided via this argument. See argument \code{start} in \code{nlrq1} for details.
}
  \item{conditional}{
logical flag. If \code{TRUE} (default), the transformation parameter is assumed to be known and this must be provided via the argument \code{lambda}. Otherwise, it is estimated via \code{\link{nlrq1}}.
}

  \item{epsilon}{
constant used to trim the values of the sample space.
}
  \item{method.rq}{
linear programming algorithm (see \code{\link{rq}}).
}
  \item{\dots}{
additional arguments.
}
}

\details{
This function implements the methods proposed by Geraci (2016) and Geraci and McLain (2018) to impute missing values using quantile regression models. Uniform values are sampled from \emph{[epsilon, 1 - epsilon]}, therefore allowing the interval to be bounded away from 0 and 1 (default is 0.001). It is possible to specify a quantile regression transformation model with parameter \code{lambda} (Geraci and Jones). The function \code{mice.impute.rrq} performs imputation based on restricted regression quantiles to avoid quantile crossing (see Geraci 2016 for details).
}

\value{

A vector of length \code{nmis} with imputations.

}

\references{
Bottai, M., & Zhen, H. (2013). Multiple imputation based on conditional quantile estimation. Epidemiology, Biostatistics, and Public Health, 10(1), e8758.

Geraci, M. (2016). Estimation of regression quantiles in complex surveys with data missing at random: An application to birthweight determinants. Statistical Methods in Medical Research, 25(4), 1393-1421.

Geraci, M., and Jones, M. C. (2015). Improved transformation-based quantile regression. Canadian Journal of Statistics, 43(1), 118-132.

Geraci, M., and McLain, A. (2018). Multiple imputation for bounded variables. Psychometrika, 83(4), 919-940.

van Buuren, S., and Groothuis-Oudshoorn, K. (2011). mice: Multivariate imputation by chained equations in R. Journal of Statistical Software, 45(3), 1--67. 
}
\author{
Marco Geraci
}

\seealso{
\code{\link{ao}}, \code{\link{tsrq}}
}

\examples{

\dontrun{

# Load package 'mice'
require(mice)

# Load data nhanes
data(nhanes)
nhanes2 <- nhanes
nhanes2$hyp <- as.factor(nhanes2$hyp)

# Impute continuous variables using quantile regression
set.seed(199)
imp <- mice(nhanes2, meth = c("polyreg", "rq", "logreg", "rq"), m = 5)

# estimate linear regression and pool results
fit <- lm.mids(bmi ~ hyp + chl, data = imp)
pool(fit)

# Impute using restricted quantile regression
set.seed(199)
imp <- mice(nhanes2, meth = c("polyreg", "rrq", "logreg", "rrq"), m = 5)
fit <- lm.mids(bmi ~ hyp + chl, data = imp)
pool(fit)

# Impute using quantile regression + Box-Cox transformation with parameter
# lambda = 0 (ie, log transformation)

set.seed(199)
imp <- mice(nhanes2, meth = c("polyreg", "rq", "logreg", "rq"), m = 5, tsf = "bc", lambda = 0)
fit <- lm.mids(bmi ~ hyp + chl, data = imp)
pool(fit)


}

}



\keyword{ multiple imputation}
\keyword{conditional quantiles}