\name{CDFMixtures}
\alias{CDFMixtures}

\title{cumulative distribution of mixture model}
\description{
returns the cdf (cumulative distribution function) of a mixture model of gaussian or log gaussians
}
\usage{
CDFMixtures(Kernels,Means,SDs,Weights,IsLogDistribution)
}

\arguments{
  \item{Kernels}{at these locations N(Means,Sdevs)*Weights is used for cdf calcuation, NOTE: Kernels are usually (but not necessarily) sorted and unique}
  \item{Means}{vector(1:L), Means of Gaussians,  L ==  Number of Gaussians}
  \item{SDs}{estimated Gaussian Kernels = standard deviations}
  \item{Weights}{optional, relative number of points in Gaussians (prior probabilities): 
                                  sum(Weights) ==1, default weight is 1/L}
  \item{IsLogDistribution}{Optional, if IsLogDistribution(i)==1, then mixture is lognormal
                                  default == 0*(1:L)}
}

\value{
List with
  \item{CDFGaussMixture}{(1:N,1),  cdf of Sum of SingleGaussians at Kernels}
  \item{CDFSingleGaussian}{(1:N,1:L)  ,cdf of mixtures at Kernels}

}
\author{Rabea Griese}

\seealso{\code{\link{Chi2testMixtures}}}
