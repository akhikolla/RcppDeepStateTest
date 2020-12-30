\name{load_gct}
\alias{load_gct}
\title{
  Load gene expression file
}
\description{
  Load gene expression data from .gct file
}
\usage{
  load_gct(file)
}
\arguments{
  \item{file}{Name of .gct file which contains gene expression data. Should be a tab-separated text file. The first row is version and the second is the dimension of expression matrix. There is an expression matrix from the third row to the end. The third row is column name of expression matrix. The first column is gene symbol and the second is the description of gene. For the remaining rows and columns, each row is a gene and each column is a sample.}
}
\value{
  A matrix with row names and column names.
}
\examples{
# Gene expression files are available after registration at Broad institute GSEA website
# http://www.broadinstitute.org/gsea

\dontrun{
filename <- "P53.gct"
expdat <- load_gct(filename)
}
}
