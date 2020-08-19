\name{KStestMixtures}
\alias{KStestMixtures}

\title{Kolmogorov-Smirnov test}
\description{
  Returns a P value and visualizes for Kolmogorov-Smirnov test of Data versus a given Gauss Mixture Model
}
\usage{
KStestMixtures(Data,Means,SDs,Weights,IsLogDistribution,PlotIt,UpperLimit,Silent)
}

\arguments{
  \item{Data}{vector of data points}
  \item{Means}{vector of Means of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities)}
  \item{IsLogDistribution}{Optional, if IsLogDistribution(i)==1, then mixture is lognormal, default vector of zeros of length 1:L}
  \item{PlotIt}{Optional, Default: FALSE, do a Plot of the compared cdfs and the KS-test distribution (Diff)}
  \item{UpperLimit}{Optional. test only for Data <= UpperLimit, Default = max(Data) i.e all Data.}
  \item{Silent}{Optional, default=TRUE, If FALSE, shows progress of computation by points (On windows systems a progress bar)}
	}
\details{
The null hypothesis is that the estimated data distribution does not differ significantly from the GMM.
If there is a significant difference, then the Pvalue is small and the null hypothesis is rejected.
}
\value{
List with
  \item{Pvalue }{Pvalue of a suiting Kolmogorov-Smirnov test, Pvalue ==0 if Pvalue <0.001}
  \item{DataKernels }{such that plot(DataKernels,DataCDF) gives the cdf(Data)}
  \item{DataCDF }{such that plot(DataKernels,DataCDF) gives the cdf(Data)}
	\item{CDFGaussMixture }{No. of data that should be in bin according to GMM}
}

\references{Smirnov, N., Table for Estimating the Goodness of Fit of Empirical Distributions. 1948, (2), 279-281.}
\author{Michael Thrun, Alfred Ultsch}

