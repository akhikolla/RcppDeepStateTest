mcpDifferences = function( x, gamma, lambda ) {
  xdiff = pmin(diff(sort(x)), gamma * lambda)
  if ( lambda > 0 ) {
    return(lambda * xdiff * ( 1 - ( xdiff / ( 2 * gamma * lambda ) ) ))
  } else {
    return(rep(0, length(xdiff)))
  }

}
