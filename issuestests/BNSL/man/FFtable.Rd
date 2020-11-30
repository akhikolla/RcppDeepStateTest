\name{FFtable}
\alias{FFtable}
\title{A faster version of fftable}
\usage{
 FFtable(df)
}
\arguments{
\item{df}{a dataframe.}
}
\description{The same procedure as fftable prepared by the R language. The program is written using Rcpp.
}
\value{
a frequency table of the last column based on the states that are determined by the other columns.
}
\author{
Joe Suzuki and Jun Kawahara
}
\seealso{ fftable }
\examples{
library(bnlearn)
FFtable(asia)
}
