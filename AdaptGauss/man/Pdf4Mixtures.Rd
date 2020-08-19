\name{Pdf4Mixtures}
\alias{Pdf4Mixtures}

\title{Calculates pdf for GMM}
\description{
  Calculate Gaussianthe probability density function for a Mixture Model
}
\usage{
Pdf4Mixtures(Data, Means, SDs, Weights,IsLogDistribution,PlotIt)
}

\arguments{
      \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 1:L}
   \item{PlotIt}{Optional: =TRUE plot of pdf}
  
}
\value{
List with
  \item{PDF4modes}{matrix, where the columns are the gaussians}
  \item{PDF}{matrix, where the columns are the gaussians weighted by Weights}
  \item{PDFmixture}{linear superpositions of PDF -  prior probabilities of Gaussians}
}
\author{Michael Thrun}
\examples{
data=c(rnorm(1000),rnorm(2000)+2,rnorm(1000)*2-1)
Pdf4Mixtures(data,c(-1,0,2),c(2,1,1),c(0.25,0.25,0.5), PlotIt=TRUE)
}
\seealso{\code{\link{PlotMixtures}}}


\keyword{GMM}
\keyword{gaussian mixture model}
\keyword{pdf}
\keyword{probability density function}