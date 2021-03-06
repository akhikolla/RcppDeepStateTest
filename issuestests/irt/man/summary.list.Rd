% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/cat_sim_helper_functions.R
\name{summary.list}
\alias{summary.list}
\title{If a list object consists of all "cat_output" objects, then it will run
summary.cat_output.}
\usage{
\method{summary}{list}(object, ...)
}
\arguments{
\item{object}{A list object consists of all "cat_output" objects.}

\item{...}{Arguments passed to the \code{summary.cat_output()} function.}
}
\value{
A data frame that summarizes the CAT outputs.
}
\description{
If a list object consists of all "cat_output" objects, then it will run
summary.cat_output.
}
\author{
Emre Gonulates
}
\keyword{internal}
