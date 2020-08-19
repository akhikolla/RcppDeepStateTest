\name{RandomLogGMM}
\alias{RandomLogGMM}
\title{Random Number Generator for Log or Gaussian Mixture Model}
\description{
	Function finds the intersections of Gaussians or LogNormals
}
\usage{
RandomLogGMM(Means,SDs,Weights,IsLogDistribution,TotalNoPoints)
}
\arguments{
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM)}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of Zeros of Length L}
   \item{TotalNoPoints}{Optional, number of point for log or GMM generated}

}

\value{            
Returns vector of [1:TotalNoPoints] of genrated points for log oder gaussian mixture model
}
\author{Alfred Ultsch,Michael Thrun, Rabea Griese}
\seealso{\code{\link{QQplotGMM}},\code{\link{Chi2testMixtures}}}
\keyword{GMM}
\keyword{log GMM}
