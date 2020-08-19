\name{Symlognpdf}
\alias{Symlognpdf}
\title{
computes a special case of log normal distribution density
}
\description{
Symlognpdf is an internal function for AdaptLGL.
}
\usage{
Symlognpdf(Data, Mean, SD)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{Data}{vector of data points used for sampling}
  \item{Mean}{Mean of log Gaussian}
  \item{SD}{Standard deviation of log Gaussian}
}

\value{
M>0 Log normal distribution density

M<0 Log normal distribution density mirrored at y axis
}

\note{
not for external usage.
}
\seealso{
AdaptLGL AdaptLGL 
}