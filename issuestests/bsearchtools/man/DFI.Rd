\name{DFI}
\alias{DFI}
\alias{as.DFI}
\alias{is.DFI}
\alias{print.DFI}
\title{Create a data.frame (or matrix) with indexes}
\description{
Turn a data.frame (or matrix) object into a DFI object allowing faster lookups on indexed columns (indexed column to be intended as DB indexes).
}
\usage{
DFI(DF, indexes.col.names=colnames(DF))
as.DFI(DF, indexes.col.names=colnames(DF)) # exactly the same as DFI()
is.DFI(x)
\method{print}{DFI}(x, \dots)
}
\arguments{
  \item{DF}{A data.frame or matrix object (must have column names defined). }
  \item{indexes.col.names}{The column names for which we want to create the indexes. Only integer,numeric,logical and character are supported, so be careful since data.frame by default turns strings into factors (see data.frame \code{stringsAsFactors} argument) }
  \item{x}{A DFI object.}
  \item{\dots}{optional arguments passed to inner \code{print} methods of data.frame and matrix .}
}
\details{

Basically, \code{DFI()} function creates a wrapper of \code{DF}. 
This wrapper contains the original data.frame or matrix plus the necessary indexes data and the class of the wrapped object.
These extra data will be used to perform faster lookups (in \code{\link[bsearchtools]{DFI.subset}} function) and can be extracted using the appropriate functions 
\code{\link[bsearchtools]{DFI.unWrap}},
\code{\link[bsearchtools]{DFI.indexes}},
\code{\link[bsearchtools]{DFI.getIndex}}. 
}
\note{
Since version 0.0.47 DFI objects do not inherit from data.frame or matrix anymore, hence they cannot be modified/subsetted using data.frame/matrix standard operators.
This has been changed since the column indexes are not recreated automatically and once the object is modified, DFI.subset could give wrong results without any warning.
To use the standard replacement and subset operators, extract the original object first using \code{DFI.unWrap(DFIobj)}.
}
\value{
  An object with class \code{"DFI"}
}
\seealso{
\code{\link[bsearchtools]{DFI.subset}}
\code{\link[bsearchtools]{DFI.unWrap}}
\code{\link[bsearchtools]{DFI.indexes}}
\code{\link[bsearchtools]{DFI.getIndex}}
}
\examples{

DF <- data.frame(Foo=c(3,5,7,1,5,8,7,10),
                 Bar=c("A","B","B","C","B","B","C","A"),
                 Baz=c(TRUE,FALSE),
                 stringsAsFactors=FALSE)
DFIobj <- DFI(DF, c("Foo","Bar")) # create a DFI from DF with indexes on "Foo" and "Bar" columns

}

