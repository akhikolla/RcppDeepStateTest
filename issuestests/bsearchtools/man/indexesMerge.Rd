\name{indexesMerge}
\alias{intersectIndexesList}
\alias{unionIndexesList}
\title{
Intersection / union of list of indexes
}
\description{
Functions to perform intersection or union of a list of integer vectors.
This functions are used by DFI.subset for AND/OR filters
}
\usage{
intersectIndexesList(lst,sorted=TRUE)
unionIndexesList(lst,sorted=TRUE)
}
\arguments{
  \item{lst}{list of integer vectors on which intersection or union must be performed}
  \item{sorted}{logical value used to specify if the returned indexes should be sorted ascending (default TRUE)}
}
\details{
The returned vector is sorted ascending.
\code{intersectIndexesList} is implemented in C++ and corresponds to \code{sort(unique(Reduce(f=intersect,x=lst)))} (without the \code{sort} function if \code{sorted=FALSE}).
\code{unionIndexesList} is partially implemented in C++ and corresponds to \code{sort(unique(Reduce(f=union,x=lst)))} (without the \code{sort} function if \code{sorted=FALSE}).
}
\value{
A vector of integers.
}
\examples{
intersectIndexesList(list(1:7,4:8,3:5))
unionIndexesList(list(1:7,4:8,3:5))
}

