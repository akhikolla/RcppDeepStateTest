\name{ub}
\alias{ub}
\alias{ubNumeric}
\alias{ubInteger}
\alias{ubLogical}
\alias{ubCharacter}
\title{Binary search based upper bound operation}
\description{
Returns the index pointing to the first element in the vector that is greater than valueToSearch.
The behavior is the same as C++ std::upper_bound function, hence, if the vector is empty it or if valueToSearch is greater than
the last element of the vector, it returns \code{length(sortedValues) + 1}.

The functions suffixed with the vector type (ubNumeric,ubLogical etc.) can be used ONLY with the specified type, otherwise the
vector is coerced, and they are (hopefully negligibly) faster then the generic ub function.

For information about NAs handling see details section.

}
\usage{
ub(sortedValues, valueToSearch)
ubInteger(sortedValues, valueToSearch)
ubNumeric(sortedValues, valueToSearch)
ubLogical(sortedValues, valueToSearch)
ubCharacter(sortedValues, valueToSearch)
}
\details{
\code{ub*} functions expect \code{sortedValues} to be a vector sorted ascending (duplicated values are allowed). 
Since the binary search functions rely on values comparison (using \code{<} operator) and \code{NA} cannot be compared by definition, 
if \code{sortedValues} vector contains \code{NA}, the result is unpredictable and NO warning is given. Hence remove them before calling these functions.
}
\arguments{
  \item{sortedValues}{A sorted atomic vector of type numeric, integer, logical or character }
  \item{valueToSearch}{The value to search. If equal to \code{NA}, \code{length(sortedValues)+1} is returned.}
}
\value{
The index pointing to the first element in the vector that is not less than (i.e. greater or equal to) valueToSearch.
}
\references{
See http://en.cppreference.com/w/cpp/algorithm/lower_bound
}
\examples{
ub(c(1,4,5,5,7,9),5) # returns 5
ub(c(1,4,5,5,7,9),10) # returns 7
ub(numeric(),10) # returns 1
}