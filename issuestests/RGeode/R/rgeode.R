#' @title  GEOmetric Density Estimation.
#
#' @description It selects the principal directions of the data and
#' performs inference. Moreover GEODE is also able to handle missing
#' data.
#'
#' @details
#' GEOmetric Density Estimation (rgeode) is a fast algorithm performing
#' inference on normally distributed data. It is essentially
#' divided in two principal steps:
#' \itemize{
#' \item  Selection of the principal axes of the data.
#' \item  Adaptive Gibbs sampler with the creation of a set of samples from
#'        the full conditional posteriors of the parameters of interest,
#'        which enable us to perform inference.
#' }
#' It takes in inputs several quantities. A rectangular
#' \eqn{(N,D)} matrix \eqn{Y}, on which we will run a Fast rank
#' \eqn{d} SVD. The conservative upper bound of the true dimension
#' of our data \eqn{d}. A set of tuning parameters. We remark that
#' the choice of the conservative upper bound \eqn{d} must be such
#' that \eqn{d>p}, with \eqn{p} real dimension, and \eqn{d << D}.
#'
#'
#' @param Y          array_like \cr
#'                   a real input matrix (or data frame), with dimensions
#'                   \eqn{(n, D)}. It is the real matrix of data.
#'
#' @param d          int, optional \cr
#'                   it is the conservative upper bound for the dimension
#'                   D. We are confident that the real dimension is smaller
#'                   then it.
#'
#' @param burn       int, optional \cr
#'                   number of burn-in to perform in our Gibbs sampler. It
#'                   represents also the stopping time that stop the choice
#'                   of the principal axes.
#'
#' @param its        int, optional \cr
#'                   number of iterations that must be performed after
#'                   the burn-in.
#'
#' @param tol        double, optional \cr
#'                   threshold for adaptively removing redundant
#'                   dimensions. It is used compared with the ratio:
#'                   \eqn{\frac{\alpha_j^2(t)}{\max \alpha_i^2(t)}}.
#'
#' @param atau       double, optional \cr
#'                   The parameter \eqn{a_\tau} of the truncated
#'                   Exponential (the prior for \eqn{\tau_j}).
#'
#' @param asigma     double, optional \cr
#'                   The shape parameter \eqn{a_\sigma} of the
#'                   truncated Gamma (the prior for \eqn{\sigma^2}).
#'
#' @param bsigma     double, optional \cr
#'                   The rate parameter \eqn{b_\sigma} of the
#'                   truncated Gamma (the prior for \eqn{\sigma^2}).
#'
#'
#' @param starttime  int, optional \cr
#'                   starting time for adaptive pruning. It must be less
#'                   then the number of burn-in.
#'
#'
#' @param stoptime   int, optional \cr
#'                   stop time for adaptive pruning. It must be less
#'                   then the number of burn-in.
#'
#' @param fast       bool, optional \cr
#'                   If \eqn{TRUE} it is run using fast d-rank SVD.
#'                   Otherwise it uses the classical SVD.
#'
#' @param c0         double, optional \cr
#'                   Additive constant for the exponent of the pruning step.
#'
#' @param c1         double, optional \cr
#'                   Multiplicative constant for the exponent of the pruning step.
#'
#' @return \code{rgeode} returns a list containing the following
#'         components:
#' \item{InD}{  array_like \cr
#'              The chose principal axes.
#'
#'           }
#'
#' \item{u}{       matrix \cr
#'                 Containing the sample from the full conditional
#'                 posterior of \eqn{u_j}s. We store each
#'                 iteration on the columns.
#'         }
#'
#' \item{tau}{     matrix \cr
#'                 Containing the sample from the full conditional
#'                 posterior of \eqn{tau_j}s.
#'
#'           }
#'
#' \item{sigmaS}{  array_like \cr
#'                 Containing the sample from the full conditional
#'                 posterior of \eqn{sigma}.
#'
#'              }
#'
#' \item{W}{       matrix \cr
#'                 Containing the principal singular vectors.
#'
#'              }
#'
#' \item{Miss}{    list \cr
#'                 Containing all the informations about missing
#'                 data. If there are not missing data this output
#'                 is not provide.
#'                 \itemize{
#'                 \item{id_m} array \cr
#'                 It contains the set of rows with missing data.
#'                 \item{pos_m} list \cr
#'                 It contains the set of missing data positions for each
#'                 row with missing values.
#'                 \item{yms} list \cr
#'                 The list contained the pseudo-observation substituting our
#'                 missing data. Each element of the list represents the simulated
#'                 data for that time.
#'                 }
#'
#'              }
#'
#'
#'
#'
#'
#' @note The part related to the missing data is filled only
#'       in the case in which we have missing data.
#'
#'
#' @references
#' \itemize{
#'
#'         \item    [1] Y. Wang, A. Canale, D. Dunson.
#'                  "Scalable Geometric Density Estimation" (2016).\cr
#' }
#'
#' @author L. Rimella, \email{lorenzo.rimella@hotmail.it}
#'
#'
#'
#' @examples
#'
#' library(MASS)
#' library(RGeode)
#'
#' ####################################################################
#' # WITHOUT MISSING DATA
#' ####################################################################
#' # Define the dataset
#' D= 200
#' n= 500
#' d= 10
#' d_true= 3
#'
#' set.seed(321)
#'
#' mu_true= runif(d_true, -3, 10)
#'
#' Sigma_true= matrix(0,d_true,d_true)
#' diag(Sigma_true)= c(runif(d_true, 10, 100))
#'
#' W_true = svd(matrix(rnorm(D*d_true, 0, 1), d_true, D))$v
#'
#' sigma_true = abs(runif(1,0,1))
#'
#' mu= W_true%*%mu_true
#' C= W_true %*% Sigma_true %*% t(W_true)+ sigma_true* diag(D)
#'
#' y= mvrnorm(n, mu, C)
#'
#' ################################
#' # GEODE: Without missing data
#' ################################
#' 
#' start.time <- Sys.time() 
#' GEODE= rgeode(Y= y, d)
#' Sys.time()- start.time
#'
#' # SIGMAS
#' #plot(seq(110,3000,by=1),GEODE$sigmaS[110:3000],ty='l',col=2,
#' #     xlab= 'Iteration', ylab= 'sigma^2', main= 'Simulation of sigma^2')
#' #abline(v=800,lwd= 2, col= 'blue')
#' #legend('bottomright',c('Posterior of sigma^2', 'Stopping time'),
#' #       lwd=c(1,2),col=c(2,4),cex=0.55, border='black', box.lwd=3)
#'        
#'        
#' ####################################################################
#' # WITH MISSING DATA
#' ####################################################################
#' 
#' ###########################
#' #Insert NaN
#' n_m = 5 #number of data vectors containing missing features
#' d_m = 1  #number of missing features
#' 
#' data_miss= sample(seq(1,n),n_m)
#' 
#' features= sample(seq(1,D), d_m)
#' for(i in 2:n_m)
#' {
#'   features= rbind(features, sample(seq(1,D), d_m))
#' }
#' 
#' for(i in 1:length(data_miss))
#' {
#'   
#'   if(i==length(data_miss))
#'   {
#'     y[data_miss[i],features[i,][-1]]= NaN
#'   }
#'   else
#'   {
#'     y[data_miss[i],features[i,]]= NaN
#'   }
#'   
#' }
#'
#' ################################
#' # GEODE: With missing data
#' ################################
#' set.seed(321)
#' start.time <- Sys.time() 
#' GEODE= rgeode(Y= y, d)
#' Sys.time()- start.time
#'
#' # SIGMAS
#' #plot(seq(110,3000,by=1),GEODE$sigmaS[110:3000],ty='l',col=2,
#' #     xlab= 'Iteration', ylab= 'sigma^2', main= 'Simulation of sigma^2')
#' #abline(v=800,lwd= 2, col= 'blue')
#' #legend('bottomright',c('Posterior of sigma^2', 'Stopping time'),
#' #       lwd=c(1,2),col=c(2,4),cex=0.55, border='black', box.lwd=3)
#'
#'
#'
#' ####################################################################
#' ####################################################################
#' @useDynLib  RGeode
#' @importFrom Rcpp sourceCpp
#' @importFrom Rcpp evalCpp
#' @import stats MASS
#' 
#' @export

   rgeode <- function(Y, d= 6, burn= 1000, its= 2000, tol= 0.01,
                         atau= 1/20, asigma= 1/2, bsigma= 1/2,
                         starttime= NULL, stoptime= NULL, fast= TRUE,
                         c0= -1, c1= -0.005)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  if(nargs()==0) stop("Insert at least a matrix.")

  if(nargs()> 13) stop("Too many arguments.")

  if(is.null(starttime) | is.null(stoptime))
  {
    if(!is.null(starttime)){warning("starttime will be modified.")}
    if(!is.null(stoptime)){warning("stoptime will be modified.")}

    starttime= round(0.1* burn)
    stoptime= round(0.8* burn)
  }

  if(c1>0)  warning("c1 is positive.")

  if(d<6)   stop("d is too small.")

  if(is.null(d)) warning("d is not specified.")

  if(tol>1) warning("The tolerance is so large.")

  if(fast!= TRUE & fast!= FALSE) stop("fast is a boolean.")

  if(d<0 | burn<0 | its<0 | tol<0 | atau<0 | asigma<0 |
     bsigma<0 | starttime<0 | stoptime<0) stop("d, burn, its, tol, atau,
                                                         asigma, bsigma, step,
                                                         starttime, stoptime must be
                                                         positive.")

  InD=    c()
  u=      c()
  tau=    c()
  sigmaS= c()
  W=      c()
  mu=     c()



  if(NA %in% Y | NaN %in% Y)
  {
    Y[is.na(Y)]= NaN

    #print("There are missing values.")
    id_m=   c()
    pos_m=  list()
    yms=    list()

    Miss= list("id_m"= id_m, "pos_m"= pos_m, "yms"= yms)

    output= list("InD"= InD, "u"= u, "tau"= tau, "sigmaS"= sigmaS,
                 "W"= W, "mu"= mu, "Miss"= Miss)

    outputAlg= rgeode_root_m(Y, d, burn, its, tol, atau, asigma,
                         bsigma, starttime, stoptime,
                         fast, c0, c1)

    #fill it
    output$InD=    outputAlg[[1]]
    output$u=      outputAlg[[2]]
    output$tau=    outputAlg[[3]]
    output$sigmaS= outputAlg[[4]]
    output$W=  outputAlg[[5]]
    output$mu= outputAlg[[6]]
    output$Miss$id_m = outputAlg[[7]]
    output$Miss$pos_m = outputAlg[[8]]
    output$Miss$yms = outputAlg[[9]]

  }
  else
  {
    #print("There are not missing values.")

    output= list("InD"= InD, "u"= u, "tau"= tau, "sigmaS"= sigmaS,
                 "W"= W, "mu"= mu)

    outputAlg= rgeode_root(Y, d, burn, its, tol, atau, asigma,
                         bsigma, starttime, stoptime,
                         fast, c0, c1)

    #fill it
    output$InD=    outputAlg[[1]]
    output$u=      outputAlg[[2]]
    output$tau=    outputAlg[[3]]
    output$sigmaS= outputAlg[[4]]
    output$W= outputAlg[[5]]
    output$mu= outputAlg[[6]]

  }

  return(output)



} # End rgeode
