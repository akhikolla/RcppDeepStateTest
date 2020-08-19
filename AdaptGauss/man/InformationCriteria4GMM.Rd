\name{InformationCriteria4GMM}
\alias{InformationCriteria4GMM}

\title{Information Criteria For GMM}
\description{
  Calculates the AIC and BIC criteria
}
\usage{
InformationCriteria4GMM(Data, Means, SDs, Weights, IsLogDistribution)
}
\arguments{
  \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default  vector of zeros of length L, LogNormal Modes are at this point only experimental}
}

\value{
List with
  \item{K}{Number of gaussian mixtures}
  \item{AIC}{Akaike Informations criterium}
	\item{BIC}{ Bayes Information criterium}
	\item{LogLikelihood}{LogLikelihood of GMM, see \code{\link{LogLikelihood4Mixtures}}}
	\item{PDFmixture}{probability density function of GMM, see \code{\link{Pdf4Mixtures}}}
	\item{LogPDFdata}{log(PDFmixture)}
}
\details{
AIC =  2*k -2*LogLikelihood, 
k = nr. of model parameter = 3*Nr. of Gaussians
One Gaussian: K=2 (Weight is then not an parameter!)
SMALL SAMPLE CORRECTION: for n= nr of Data and n < 40 * k, AIC is adjusted to AIC=AIC+ (2*k*(k+1))/(n-k-1)

 BIC = k* log(n) - 2*LogLikelihood
 
 Only for a Gaussian Mixture Model (GMM) verified, for the Log Gaussian, Gaussian, Log Gaussian (LGL) Model only experimental
}
\references{
 Aubert, A. H., Thrun, M. C., Breuer, L., & Ultsch, A.: Knowledge discovery from data structure: hydrology versus biology controlled in-stream nitrate concentration, Scientific reports, Vol. (in revision), pp., 2016.

 Aho, K., Derryberry, D., & Peterson, T.: Model selection for ecologists: the worldviews of AIC and BIC. Ecology, 95(3), pp. 631-636, 2014.
}
\author{Michael Thrun}

\keyword{AIC}
\keyword{BIC}
\keyword{Akaike informations criterium}
\keyword{Bayes information criterium}