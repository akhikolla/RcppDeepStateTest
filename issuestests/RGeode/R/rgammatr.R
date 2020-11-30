#' @title  Random generator for a Truncated Gamma distribution.
#
#' @description Simulate random number from a truncated Gamma distribution.
#
#' @details
#' It provide a way to simulate from a truncated Gamma distribution with
#' given pameters \eqn{A,B} and range \eqn{range}. This will be used
#' during the posterior sampling in th Gibbs sampler.
#'
#' @param n       int, optional \cr
#'                number of simulations.
#'
#' @param A       double, optional \cr
#'                shape parameter of the distribution.
#'
#' @param B       double, optional \cr
#'                rate parameter of the distribution.
#'
#' @param range   array_like, optional \cr
#'                domain of the distribution, where we truncate our
#'                Gamma. \eqn{range(0)} is the min of the range and
#'                \eqn{range(1)} is the max of the range.
#'
#'
#'
#' @return \code{rgammatr} returns the simulated value of the distribution:
#'
#' \item{u}{  double \cr
#'            it is the simulated value of the truncated Gamma
#'            distribution. It will be a value in \eqn{(range(0),range(1))}.
#'             }
#'
#'
#'
#' @references
#' \itemize{
#'
#'  \item   [1] Y. Wang, A. Canale, D. Dunson.
#'          "Scalable Geometric Density Estimation" (2016).\cr
#'          The implementation of rgammatr is inspired to the Matlab
#'          implementation of gamrndtruncated by Ye Wang.
#' }
#'
#' @author L. Rimella, \email{lorenzo.rimella@hotmail.it}
#' @examples
#' #Simulate a truncated Gamma with parameters 1,2 in the range
#' #1,5.
#' #Set the range:
#' range<- c(1,5)
#'
#' #Simulate the truncated Gamma
#' set.seed(123)
#' vars1<-rgammatr(1000,1,2,range)
#'
#' #Look at the histogram
#' hist(vars1,freq=FALSE,ylim=c(0,2),xlim = c(0,5))
#' lines(density(vars1))
#'
#' #Compare with a non truncated Gamma
#' set.seed(123)
#' vars2<-rgamma(1000,1,2)
#'
#'
#' #Compare the two results
#' lines(density(vars2),col='red')
#'
#' #Observation: simulate without range is equivalent to simulate from
#' #rgamma(1000,1,2)
#'
#'@import stats
#'
#' @export
   rgammatr <- function(n=1, A=0, B=1, range=NULL)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  if(nargs()==0) warning("No input arguments.")

  if(range[1]>range[2]) stop("Wrong range!")

  if(is.null(range))
  {
    warning("No range provided in the truncated Gamma. A simple Gamma random variable is simulated.")
    return(rgamma(n, shape= A, rate= B))
  }

  a1= range[1]
  a2= range[2]
  smallvalue = 1e-8

  cdf1 = pgamma(a1, shape= A, rate= B)
  cdf2 = pgamma(a2, shape= A, rate= B)

  # If cdf1 and cdf2 are both so close to one we simply set u as the
  # right extreme of the truncation. If they are both close to zero
  # we set them as equal to the left extreme.
  if(  ((cdf1>1-smallvalue) & (cdf2>1-smallvalue)) |
       ((cdf1<smallvalue) & (cdf2 < smallvalue))  )
  {
    #warning("The chosen range is really small!")
    u = rep(a1*((cdf1>1-smallvalue) & (cdf2>1-smallvalue)) +
              a2*((cdf1<smallvalue) & (cdf2 < smallvalue)),n)
  }

  # Otherwise we simulate from a truncated Gamma according to the
  # transformation:
  # Ftrunc(x)= \frac{FGamma(x)-FGamma(a1)}{FGamma(a2)-FGamma(a1)}

  else
  {
    u = qgamma(cdf1+ runif(n)*(cdf2- cdf1), shape= A, rate= B);
  }

  return(u)

  }
