\name{bsearchtools-package}
\alias{bsearchtools-package}
\alias{bsearchtools}
\docType{package}
\title{
Binary Search Tools
}
\description{
Exposes the binary search based functions of the C++ standard library 
(std::lower_bound, std::upper_bound) plus other convenience functions, allowing faster lookups on sorted vectors.
It also includes a lightweight data.frame/matrix wrapper (DFI), which automatically creates indexes on the columns for faster lookups.
}
\details{
\tabular{ll}{
Package: \tab bsearchtools\cr
Type: \tab Package\cr
Version: \tab 0.0.61\cr
Date: \tab 2017-02-22\cr
License: \tab GPL (>= 2)\cr
}

This package allows to perform the most common binary search operations on sorted vectors 
(integer, numeric, bool and charater vectors are supported).
It exposes lower-bound/upper-bound functions working exactly like their the C++ standard library counterparts, 
and some convenience functions allowing efficient values and ranges lookups.

Note that these functions are especially designed to be used for non-vectorized operations (e.g. inside loops);
for vectorized operations, the great \code{data.table} package already fullfills basically every R programmer needs.
}
\author{
Marco Giuliano

Maintainer: Marco Giuliano <mgiuliano.mail@gmail.com>
}
\references{
Project repository : https://github.com/digEmAll/bsearchtools/

cpp reference page : http://en.cppreference.com/w/
}
\keyword{ package }
\keyword{ manip }
\keyword{ iteration }
\keyword{ programming }
\seealso{
\code{\link[base]{sort}},
\code{\link[base]{order}},
\code{\link[data.table]{data.table}}
}
\examples{
require(bsearchtools)

######################################################
### get indexes of values in range
### search values in range [2,4]

# N.B. v must be sorted !
v1 <- sort(c(3,5,7,10,4,8,13,3,2))

indexesInRangeNumeric(v1,2,4)
# is identical to:
which(v1 >= 2 & v1 <= 4)

######################################################
### What if vector is not sorted ? 
### (and we're going to perform a lot of lookups on it)

v2 <- c(3,5,7,10,4,8,13,3,2)

# we can create two intermediate vectors
ordIdxs <- order(v2)
sortedV2 <- v2[ordIdxs]

# then use them as follows :
ordIdxs[indexesInRangeNumeric(sortedV2,2,4)]

# this returns the same indexes :
# N.B. : 'which' returns ascending indexes while the previous line does not:
# sort the result if you want them ascending
which(v2 >= 2 & v2 <= 4)

######################################################
###### N.B. the previous code is basically what is performed by DFI objects under the hood
######      check DFI function documentation for further information
DF <- data.frame(v2=v2)
DFIobj <- DFI(DF)
indexes <- DFI.subset(DFIobj,RG('v2',2,4),return.indexes=TRUE)

\dontrun{
######################################################
### big example to measure the performance difference
set.seed(123) # for reproducibility
sortedValues <- sort(sample(1:1e4,1e5,replace=TRUE))

# measure time difference doing same operation 500 times
tm1 <- system.time( for(i in 1:500) res2 <- which(sortedValues >= 7000 & sortedValues <= 7500))
tm2 <- system.time( for(i in 1:500) res1 <- indexesInRangeInteger(sortedValues,7000,7500))

print(paste("'which' took:",tm1["elapsed"]))
print(paste("'indexesInRangeInteger' took:",tm2["elapsed"]))

}


}
