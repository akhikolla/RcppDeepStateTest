\name{lb}
\alias{lb}
\alias{lbNumeric}
\alias{lbInteger}
\alias{lbLogical}
\alias{lbCharacter}
\title{Binary search based lower bound operation}
\description{
Returns the index pointing to the first element in the vector that is not less than (i.e. greater or equal to) valueToSearch.
The behavior is the same as C++ std::lower_bound function, hence, if the vector is empty or valueToSearch is lower than
the first element of the vector, it returns the first index (i.e. 1).

The functions suffixed with the vector type (lbNumeric,lbLogical etc.) can be used ONLY with the specified type, otherwise the
vector is coerced, and they are (hopefully negligibly) faster then the generic lb function.

For information about NAs handling see details section.

}
\usage{
lb(sortedValues, valueToSearch)
lbInteger(sortedValues, valueToSearch)
lbNumeric(sortedValues, valueToSearch)
lbLogical(sortedValues, valueToSearch)
lbCharacter(sortedValues, valueToSearch)
}
\details{
\code{lb*} functions expect \code{sortedValues} to be a vector sorted ascending (duplicated values are allowed). 
Since the binary search functions rely on values comparison (using \code{<} operator) and \code{NA} cannot be compared by definition, 
if \code{sortedValues} vector contains \code{NA}, the result is unpredictable and NO warning is given. Hence remove them before calling these functions.
}
\arguments{
  \item{sortedValues}{A sorted atomic vector of type numeric, integer, logical or character.}
  \item{valueToSearch}{The value to search. If equal to \code{NA}, \code{1} is returned.}
}
\value{
The index pointing to the first element in the vector that is not less than (i.e. greater or equal to) valueToSearch.
}
\references{
See http://en.cppreference.com/w/cpp/algorithm/lower_bound
}
\examples{
lb(c(1,4,5,5,7,9),5) # returns 3
lb(c(1,4,5,5,7,9),-1) # returns 1
lb(numeric(),-1) # returns 1
}