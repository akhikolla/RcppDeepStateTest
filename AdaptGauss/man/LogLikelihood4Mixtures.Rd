\name{LogLikelihood4Mixtures}
\alias{LogLikelihood4Mixtures}

\title{LogLikelihood for Gaussian Mixture Models}
\description{
  Computes the LogLikelihood for Gaussian Mixture Models.
}
\usage{
LogLikelihood4Mixtures(Data, Means, SDs, Weights, IsLogDistribution)
}

\arguments{
  \item{Data}{ Data for empirical PDF. Has to be an Array of values. NaNs
  and NULLs will be deleted }
  \item{Means}{ Optional: Means of gaussians of GMM. }
  \item{SDs}{ Optional: StandardDevations of gaussians of GMM. (Has to be the same length as Means) }
  \item{Weights}{ Optional: Weights of gaussians of GMM. (Has to be the same length as Means) }
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 1:L}
	}
\value{
List with
  \item{LogLikelihood}{LogLikelihood = = sum(log(PDFmixture)}
  \item{LogPDF}{=log(PDFmixture)}
  \item{PDFmixture}{die Probability density function for each point}
}
 \references{
Pattern Recogintion and Machine Learning, C.M. Bishop, 2006, isbn: ISBN-13: 978-0387-31073-2, p. 433 (9.14)
}
\author{Alfred Ultsch, Catharina Lippmann}

