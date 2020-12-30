\name{multiec}
\alias{multiec}
\alias{print.mlteqc}

\title{Multiple Equating Coefficients}
\description{Calculates the equating coefficients between multiple forms.}
\usage{
multiec(mods, base = 1, method = "mean-mean", se = TRUE, nq = 30, start = NULL, 
	eval.max = 100000)
}
\arguments{
  \item{mods}{an object of the class \code{\link{modIRT}} containing item parameter
  coefficients and their covariance matrix of the forms to be equated.
}
\item{base}{
  integer value indicating the base form.
}
\item{method}{
  the method used to compute the equating coefficients.
  This should be one of "\code{mean-mean}", "\code{mean-gmean}", "\code{irf}" or "\code{trf}"
  (see details).
}
\item{se}{
  logical; if \code{TRUE} the standard errors of the equating coefficients and
  the synthetic item parameters are computed.
}
\item{nq}{
  number of quadrature points used for the Gauss-Hermite quadrature for
  methods "\code{irf}" or "\code{trf}".
}
\item{start}{
  initial values. This can be a vector containing the A and B equating coefficients excluding
  the base form, or an object of class \code{mlteqc} returned by function \code{multiec}.
  Used only with methods "\code{irf}" and "\code{trf}".
}
\item{eval.max}{
  maximum number of evaluations of the objective function allowed.
  Used only with methods "\code{irf}" and "\code{trf}".
}
}
\details{
  The methods implemented for the computation of the multiple equating coefficients are
  the multiple mean-mean method ("\code{mean-mean}"),
  the multiple mean-geometric mean method ("\code{mean-gmean}"),
  the multiple item response function method ("\code{irf}") and
  the multiple test response function method ("\code{trf}").

}
\value{
	An object of class \code{mlteqc} with components
  \item{A}{A equating coefficients.}
  \item{B}{B equating coefficients.}
  \item{se.A}{standard errors of A equating coefficients.}
  \item{se.B}{standard errors of B equating coefficients.}
  \item{varAB}{covariance matrix of equating coefficients.}
  \item{as}{synthetic discrimination parameters \eqn{\hat a_j^*}.}
  \item{bs}{synthetic difficulty parameters \eqn{\hat b_j^*}.}
  \item{se.as}{standard errors of synthetic discrimination parameters.}
  \item{se.bs}{standard errors of synthetic difficulty parameters.}
  \item{tab}{data frame containing item names (\code{Item}), 
	item parameters of all the forms (e.g. \code{T1}, \dots, \code{T3}), 
	and item parameters of all the forms converted 
	in the scale of the base form (e.g. \code{T3.as.T1}).}
  \item{varFull}{list of covariance matrices of the item parameters 
  of every form.}
  \item{partial}{partial derivatives of equating coefficients 
  with respect to the item parameters.}
  \item{itmp}{number of item parameters of the IRT model.}
  \item{method}{the equating method used.}
  \item{basename}{the name of the base form.}
  \item{convergence}{An integer code. 0 indicates successful convergence.
  Returned only with methods "\code{irf}" and "\code{trf}".}
}
\references{
	Battauz, M. (2017). Multiple equating of separate IRT calibrations.
	\emph{Psychometrika}, \bold{82}, 610--636.
	
  Haberman, S. J. (2009). Linking parameter estimates derived from an
  item response model through separate calibrations.
  ETS Research Report Series, 2009, i-9.
}
\author{
  Michela Battauz
}

\seealso{
  \code{\link{modIRT}}, \code{\link{score.mlteqc}}
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
}

