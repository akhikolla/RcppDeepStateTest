\name{rank_by_s2n}
\alias{rank_by_s2n}
\title{
  Ranking genes by signal to noise ratio
}
\description{
  Ranking genes by signal to noise ratio according to their expression data.
}
\usage{
  rank_by_s2n(expmat, label)
}
\arguments{
  \item{expmat}{A matrix of gene expression data. Each row is a gene and each column is a sample.}
  \item{label}{An integer vector of encoded pheotypes. Its value is 0 and 1. Its length should match the column number of expression matrix.} 
}
\value{
  A vector of rank of each gene according to signal to noise ratio.
}
\examples{
expdat <- matrix(rnorm(500), nrow = 25, ncol = 20)
label <- rep(c(0, 1), 10)
ranklist <- rank_by_s2n(expdat, label)
}
