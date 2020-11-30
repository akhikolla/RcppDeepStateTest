\name{ds_gsa}
\alias{ds_gsa}
\title{
  Gene set analysis via dynamic slicing
}
\description{
  Gene set analysis via dynamic slicing.
}
\usage{
  ds_gsa(expdat, geneset, label, generank, ..., lambda = 1, bycol = FALSE,
         minsize = 15, maxsize = 500, randseed = 11235, rounds = 1000)
}
\arguments{
  \item{expdat}{Either a character string of gene expression file name (.gct file), or an expression matrix with rownames, each row is a gene and each column is a sample.}
  \item{geneset}{Either a character string of gene set file name (.gmt file), or a list contains a vector of gene set names, a vector of gene set description and a list of gene symbols in each gene set.}
  \item{label}{Either a character string of phenotypes file (.cls file), or a list contains a vector of types of pheotype and a vector of encoded pheotypes of samples. It should match gene expression matrix.}
  \item{generank}{Either an integer vector of rank of each gene according to some statistic, or a character string naming a function which takes gene expression matrix as input and returns a vector of gene rank (not tie).}
  \item{...}{Parameters of the function specified (as a character string) by \code{generank}.}
  \item{lambda}{Penalty for introducing an additional slice in dynamic slicing procedure, which is used to avoid making too many slices. It corresponds to the type I error under the scenario that the two variables are independent. \code{lambda} should be greater than 0.}
  \item{bycol}{Type of permutation, by row (default) or by column. Permutation by row means shuffling the gene rank. Permutation by column means shuffling pheotypes then obtain gene rank.}
  \item{minsize}{Minimum number of genes in genesets to be considered.}
  \item{maxsize}{Maximum number of genes in genesets to be considered.}
  \item{randseed}{Optional initial seed for random number generator (integer).}
  \item{rounds}{Number of permutations for estimating significant level of results.}
}
\details{
  \code{ds_gsa} performs gene set analysis via dynamic slicing. It returns the DS statistics and slicing strategy of each gene set.
  \code{ds_gsa} does not attempt to integrate the ranking method into it. It requires ranking method or directly the gene rank as a parameter. Leaving ranking method as an optional input parameter is convenience for users who would like to use any ranking methods they want.
}
\value{
  A list with informations of gene sets whose size satisfy the minimum and maximum size thresholds. Its contains the following components:
  \item{set_name}{A vector of gene set names.}
  \item{set_size}{A vector of gene set sizes.}
  \item{DS_value}{A vector of dynamic slicing statistic of each gene set.}
  \item{pvalue}{A vector of \emph{p}-value of each gene set.}
  \item{FDR}{A vector of FDR of each gene set.}
  \item{slices}{A list of slicing strategy of each gene set. Each component is a matrix of slices.}  
}
\references{
  Jiang, B., Ye, C. and Liu, J.S. Non-parametric \emph{K}-sample tests via dynamic slicing. \emph{Journal of the American Statistical Association}, 110(510): 642-653, 2015.

  Subramanian, A., Tamayo, P., Mootha, V. K., \emph{et al}. Gene set enrichment analysis: a knowledge-based approach for interpreting genome-wide expression profiles. \emph{Proceedings of the National Academy of Sciences of the United States of America}, 2005, 102(43): 15545-15550.
  
  Benjamini, Y. and Hochberg, Y. Controlling the false discovery rate: a practical and powerful approach to multiple testing. \emph{Journal of the Royal Statistical Society. Series B (Methodological)}, 1995, 57(1): 289-300.
}
\seealso{
  \code{\link{ds_k}}.
}
\examples{
##  Loading data from files
\dontrun{
gctpath <- "P53.gct"
clspath <- "P53.cls"
gmtpath <- "C2.gmt"
expdat <- load_gct(gctpath)
label <- load_cls(clspath)
geneset <- load_gmt(gmtpath)
fc <- function(x, label)
{
  d0 <- apply(x[,which(label == 0)], 1, mean)
  d1 <- apply(x[,which(label == 1)], 1, mean)
  d <- d1 / d0
  return(order(d))
}
ds_gsa_obj <- ds_gsa(expdat, geneset, label, "fc", lambda = 1.2, bycol = TRUE,
                     minsize = 15, maxsize = 500, randseed = 11235, rounds = 100)
}
}
