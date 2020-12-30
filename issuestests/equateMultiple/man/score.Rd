\name{score.mlteqc}
\alias{score.mlteqc}

\title{
	Scoring of multiple forms
}
\description{
	Relates number-correct scores on multiple forms.
}
\usage{
\method{score}{mlteqc}(obj, method="TSE", D=1, scores=NULL,  se=TRUE, nq=30, 
  w=0.5, theta=NULL, weights=NULL, \dots)
}
\arguments{
	\item{obj}{object of the class \code{mlteqc} returned by function \code{\link{multiec}}.}
	\item{method}{the scoring method to be used. This should be one of "\code{TSE}" 
		(the default) for true score equating or "\code{OSE}" for observed score equating.}
	\item{D}{constant D of the IRT model used to estimate item parameters.}
	\item{scores}{integer values to be converted.}
	\item{se}{logical; is \code{TRUE} standard errors of equated scores are computed.}
	\item{nq}{number of quadrature points used to approximate integrals with observed score equating. 
		Used only if arguments \code{theta} and \code{weights} are \code{NULL}.}
	\item{w}{synthetic weight for population 1. It should be a number between 0 and 1.}
	\item{theta}{vector of ability values used to approximate integrals with observed score equating.}
	\item{weights}{vector of weights used to approximate integrals with observed score equating.}
	\item{\dots}{further arguments passed to or from other methods.}
}
\details{
	In this function common items are internal, i.e. they are used for scoring the test.
}
\value{
	A data frame containing theta values (only for true score equating),
	scores of the form chosen as base,
	equated scores of all other forms,
	and standard errors of equated scores.
}
\references{
	Kolen, M.J. and Brennan, R.L. (2014). \emph{Test equating, scaling, 
	and linking: methods and practices}, 3nd ed., New York: Springer.

	Ogasawara, H. (2001). Item response theory true score equatings and
	their standard errors. \emph{Journal of Educational and Behavioral Statistics}, 
	\bold{26}, 31--50.

	Ogasawara, H. (2003). Asymptotic standard errors of IRT 
	observed-score equating methods. \emph{Psychometrika}, 
	\bold{68}, 193--211.
}
\author{
	Michela Battauz
}
\seealso{
	\code{\link{multiec}}
}
\examples{
data(est2pl)
# prepare the data
mods <- modIRT(coef = est2pl$coef, var = est2pl$var, display = FALSE)

# Estimation of the equating coefficients with the multiple item response function method
eqIRF<-multiec(mods = mods, base = 1, method = "irf")
summary(eqIRF)

# scoring using the true score equating method
score(eqIRF)

# scoring using observed score equating method, without standard errors
score(eqIRF, method = "OSE", se = FALSE)
}

