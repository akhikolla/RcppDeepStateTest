#' @title Threshold probability (p(t))
#'
#' @description The decreasing function for the adptive puning.
#
#'
#' @param t   int \cr
#'            The current iteration at which the probability of an adaption is calculated.
#'
#'
#' @param c0  double \cr
#'            Additive constant at the exponent-
#'
#' @param c1  double \cr
#'            Multiplicative constant at the exponent.
#'
#'
#'
#' @return \code{p} returns the threshold of interest:
#'
#' \item{p(t)}{  double \cr
#'             It is p(t)= \eqn{exp{c0+c1*t}}.
#'             }
#'
#'
#' @references
#' \itemize{
#'
#'  \item   [1] A. Canale, D. Dunson, Y. Wang.
#'          "Scalable Geometric Density Estimation" (2016).\cr
#'          (available at \url{https://arxiv.org/abs/1410.7692}).\cr
#'          The implementation of rgammatr is inspired to the Matlab
#'          implementation of rexptrunc by Ye Wang.
#' }
#'
#' @author L. Rimella, \email{lorenzo.rimella@hotmail.it}
#' 
#' @examples 
#' t = 10
#' c0= -1
#' c1= 10
#' 
#' p(t, c0, c1)

#' @export

   p <- function(t, c0, c1)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  return( exp(c0+c1*t) )

}
