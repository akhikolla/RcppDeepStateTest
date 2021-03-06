% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/subset_tcorpus.r
\name{subset.tCorpus}
\alias{subset.tCorpus}
\title{S3 subset for tCorpus class}
\usage{
\method{subset}{tCorpus}(x, subset = NULL, subset_meta = NULL,
  window = NULL, ...)
}
\arguments{
\item{x}{a tCorpus object}

\item{subset}{logical expression indicating rows to keep in the tokens data.}

\item{subset_meta}{logical expression indicating rows to keep in the document meta data.}

\item{window}{If not NULL, an integer specifiying the window to be used to return the subset. For instance, if the subset contains token 10 in a document and window is 5, the subset will contain token 5 to 15. Naturally, this does not apply to subset_meta.}

\item{...}{not used}
}
\description{
S3 subset for tCorpus class
}
\examples{
tc = create_tcorpus(sotu_texts, doc_col='id')

## subset to keep only tokens where token_id <= 20 (i.e.first 20 tokens)
tcs1 = subset(tc, token_id < 20)
tcs1

## subset to keep only documents where president is Barack Obama
tcs2 = subset(tc, subset_meta = president == 'Barack Obama')
tcs2
}
