#' @title  Random generator for a Truncated Exponential distribution.
#
#' @description Simulate random number from a truncated Exponential distribution.
#
#' @details
#' It provide a way to simulate from a truncated Exponential
#' distribution with given pameter \eqn{\lambda} and the range \eqn{range}.
#' This will be used during the posterior sampling in th Gibbs sampler.
#'
#' @param n       int, optional \cr
#'                number of simulations.
#'
#' @param lambda  double, optional \cr
#'                parameter of the distribution.
#'
#' @param range   array_like, optional \cr
#'                domain of the distribution, where we truncate our
#'                Exponential. \eqn{range(0)} is the min of the range
#'                and \eqn{range(1)} is the max of the range.
#'
#'
#' @return \code{rexptr} returns the simulated value of the
#' distribution:
#'
#' \item{u}{  double \cr
#'            it is the simulated value of the truncated Exponential
#'            distribution. It will be a value in \eqn{(range(0),
#'            range(1))}.
#'             }
#'
#'
#' @references
#' \itemize{
#'
#'  \item   [1] Y. Wang, A. Canale, D. Dunson.
#'          "Scalable Geometric Density Estimation" (2016).\cr
#'          The implementation of rgammatr is inspired to the Matlab
#'          implementation of rexptrunc by Ye Wang.
#' }
#'
#' @author L. Rimella, \email{lorenzo.rimella@hotmail.it}
#'
#' @examples
#' #Simulate a truncated Exponential with parameters 0.5 in the range
#' #5,Inf.
#' #Set the range:
#' range<- c(1,Inf)
#'
#' #Simulate the truncated Gamma
#' set.seed(123)
#' vars1<-rexptr(1000,0.5,range)
#'
#' #Look at the histogram
#' hist(vars1,freq=FALSE,ylim=c(0,2),xlim = c(0,5))
#' lines(density(vars1))
#'
#' #Compare with a non truncated Exponential
#' set.seed(123)
#' vars2<-rexp(1000,0.5)
#'
#'
#' #Compare the two results
#' lines(density(vars2),col='red')
#'
#' #Observation: simulate without range is equivalent to simulate from
#' #rexp(1000,0.5)
#'
#' @import stats
#'
#' @export

   rexptr <- function(n=1, lambda=1, range=NULL)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  if(is.null(range))
  {
    warning("No range provided in the truncated Exponential. A simple Exponential random variable is simulated.")
    return(rexp(n, rate= lambda))
  }

  a1= range[1]
  a2= range[2]
  smallvalue = 1e-8

  cdf1 = pexp(a1, rate= lambda)
  cdf2 = pexp(a2, rate= lambda)

  if(cdf2-cdf1< smallvalue)
  {
    u = a1
  }

  # Otherwise we simulate from a truncated Exp according to the
  # transformation:
  # Ftrunc(x)= \frac{FExp(x)-FExp(a1)}{FExp(a2)-FExp(a1)}

  else
  {
    u = qexp(cdf1+ runif(n)*(cdf2- cdf1), rate= lambda);
  }

  return(u)

}


