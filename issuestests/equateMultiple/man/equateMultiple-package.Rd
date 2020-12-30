\name{EquateMultiple-package}
\alias{EquateMultiple-package}
\alias{EquateMultiple}
\docType{package}
\title{Equating of Multiple Forms}
\description{The \bold{EquateMultiple} package implements IRT-based methods to
equate simultaneously many forms calibrated separately.
This package estimates the equating coefficients to convert the item 
parameters and the ability values to the scale of the base form.
It can be applied to a large number of test forms, as well as to 2 forms.
The computation of the equated scores is also implemented.
}
\details{
This package implements the methods proposed in Haberman (2009) and Battauz (2017).
Function \code{\link{multiec}} computes the equating coefficients to convert the
item parameters and the ability values to the scale of the base form.
The methods implemented are: multiple mean-geometric mean (Haberman, 2009),
multiple mean-mean, multiple item response function, and multiple test
response function (Battauz, 2017).
The function provides the equating coefficients, the synthetic item parameters
and the standard errors of the equating coefficients and the synthetic item parameters.
Equated scores can be computed using true score equating and 
observed score equating methods. Standard errors of equated scores
are also provided.
}
\author{
	Michela Battauz
	
	Maintainer: Michela Battauz <michela.battauz@uniud.it>
}
\references{
	Battauz, M. (2017). Multiple equating of separate IRT calibrations.
	\emph{Psychometrika}, \bold{82}, 610--636. doi:10.1007/s11336-016-9517-x.
	
  Haberman, S. J. (2009). Linking parameter estimates derived from an
  item response model through separate calibrations.
  ETS Research Report Series, 2009, i-9. doi:10.1002/j.2333-8504.2009.tb02197.x.
}
\keyword{ package }
\seealso{
\code{\link[equateIRT:equateIRT-package]{equateIRT}}
}
\examples{
data(est2pl)
# prepare the data
mods <- modIRT(coef = est2pl$coef, var = est2pl$var, display = FALSE)
# Estimation of the equating coefficients with the multiple mean-mean method
eqMM <- multiec(mods = mods, base = 1, method = "mean-mean")
summary(eqMM)

# Estimation of the equating coefficients with the 
# multiple mean-geometric mean method (Haberman, 2009)
eqMGM <- multiec(mods = mods, base = 1, method = "mean-gmean")
summary(eqMGM)

# Estimation of the equating coefficients with the multiple item response function method
eqIRF <- multiec(mods = mods, base = 1, method = "irf")
summary(eqIRF)

# Estimation of the equating coefficients with the multiple item response function method
# using as initial values the estimates obtained with the multiple mean-geometric mean method
eqMGM <- multiec(mods = mods, base = 1, method = "mean-gmean", se = FALSE)
eqIRF <- multiec(mods = mods, base = 1, method = "irf", start = eqMGM)
summary(eqIRF)

# Estimation of the equating coefficients with the multiple test response function method
eqTRF <- multiec(mods = mods, base = 1, method = "trf")
summary(eqTRF)

# scoring using the true score equating method and equating coefficients 
# obtained with the multiple item response function method
score(eqIRF)
}
