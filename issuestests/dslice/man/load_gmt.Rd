\name{load_gmt}
\alias{load_gmt}
\title{
  Load gene set file
}
\description{
  Load gene set from .gmt file
}
\usage{
  load_gmt(file)
}
\arguments{
  \item{file}{Name of .gmt file which contains gene sets. Should be a tab-separated text file. Each row is a gene set. The first column is gene set name and the second is its description. Remaining columns are gene symbols of genes in this set.}
}
\value{
  A list with components:
  \item{set_name}{Vector of gene set names.}
  \item{set_description}{Vector of gene set descriptions.}
  \item{gene_symbol}{List of gene symbols in each gene set.}
}
\examples{
# Gene set files are available after registration at Broad institute GSEA website
# http://www.broadinstitute.org/gsea

\dontrun{
filename <- "C2.gmt"
geneset <- load_gmt(filename)
}
}

