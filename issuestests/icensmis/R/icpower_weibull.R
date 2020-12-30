#' Study design in the presence of error-prone diagnostic tests and 
#' self-reported outcomes for Weibull model
#' 
#' This functions works same way as \code{\link{icpower}} function 
#' except that it assumes the survival function follows Weibull
#' distribution. The scale parameter is assumed to be same for
#' both treatment and control groups.
#' This can be used estimate power and sample size for interval
#' censored data using Weibull model, which is a cpecial case
#' when both sensitivity and specificity being 1.
#' 
#' @param HR hazard ratio under the alternative hypothesis.
#' @param sensitivity the sensitivity of test.
#' @param specificity the specificity of test
#' @param shape shape parameter of the Weibull distribution for reference group
#' @param scale scale parameter of the Weibull distributions. Same for all groups
#' @param times the visit times
#' @param N a vector of sample sizes to calculate corresponding powers. If one 
#'   needs to calculate sample size, then set to NULL.
#' @param power a vector of powers to calculate corresponding sample sizes. If 
#'   one needs to calculate power, then set to NULL.
#' @param rho proportion of subjects in baseline(reference) group.
#' @param alpha type I error.
#' @param pmiss a value or a vector (must have same length as survivals) of the 
#'   probabilities of each test being randomly missing at each test time. If 
#'   pmiss is a single value, then each test is assumed to have an identical 
#'   probability of missingness.
#' @param pcensor a value or a vector (must have same length as testtimes) of
#' the probability of censoring at each visit, assuming censoring process
#' is independent on other missing mechanisms.
#' @param design missing mechanism: "MCAR" or "NTFP".
#' @param negpred baseline negative predictive value, i.e. the probability of 
#'   being truely disease free for those who were tested (reported) as disease 
#'   free at baseline. If baseline screening test is perfect, then negpred = 1.
#'   
#' @details To calculate sample sizes for a vector of powers, set N = NULL. To 
#'   calculate powers for a vector of sample sizes, set power = NULL. One and 
#'   only one of power and N should be specified, and the other set to NULL. 
#'   This function uses an enumeration algorithm to calculate the expected 
#'   Fisher information matrix. The expected Fisher information matrix is used 
#'   to obtain the variance of the coefficient corresponding to the treatment 
#'   group indicator.
#'   
#' @return \itemize{ \item result: a data frame with calculated sample size and 
#'   power \item I1 and I2: calculated unit Fisher information matrices for each
#'   group, which can be used to calculate more values of sample size and power 
#'   for the same design without the need to enumerate again }
#'   
#' @note   When diagnostic test is perfect, i.e. sensitivity=1 and 
#'   specificity=1, use \code{\link{icpowerpf}} instead to obtain significantly 
#'   improved computational efficiency.
#'   
#' @seealso \code{\link{icpowerpf}} \code{\link{icpower}}
#'   
#' @examples
#' 
#' icpower_weibull(2, 0.75, 0.98, 1, 0.1, 1:8, power = 0.9)$result
#' 
#' # Interval censoring
#' icpower_weibull(2, 1, 1, 1, 0.1, 1:8, power = 0.9)$result
#' 
#' @export
#' 

# TO DO--------------------------------------------------------------
# 1. Replace argument times with cumulative indicidence
# 2. Refactor the code chunk to make sure not using same variable
#    repeatedly across treatment groups
#--------------------------------------------------------------------

icpower_weibull <- function(
  HR, sensitivity, specificity, shape, scale, times, N = NULL,
  power = NULL, rho = 0.5, alpha = 0.05, pmiss = 0, pcensor = 0,
  design = "MCAR", negpred = 1) {
  
  miss 	<- any(pmiss != 0) || any(pcensor != 0)
  beta  	<- log(HR)
  u <- log(scale)
  v <- shape
  J <- length(times)
  
  if (length(pmiss)==1) pmiss <- rep(pmiss, J)
  if (length(pcensor) == 1) pcensor <- rep(pcensor, J)
  
  if (sensitivity==1 & specificity==1) {
    design <- "NTFP"
  }
  
  if (design=="MCAR" & !miss) {	
    Dm <- powerdmat1(sensitivity, specificity, J, negpred)
    prob <- 1	
  } else if (design=="MCAR" & miss) {
    Dm <- powerdmat2(sensitivity, specificity, J, negpred, pmiss, pcensor)
    prob <- Dm[[2]]
    Dm <- Dm[[1]]
  } else if (design=="NTFP" & !miss) {
    Dm <- powerdmat3(sensitivity, specificity, J, negpred)
    prob <- 1
  } else if (design=="NTFP" & miss) {
    Dm <- powerdmat4(sensitivity, specificity, J, negpred, pmiss, pcensor)
    prob <- Dm[[2]]
    Dm <- Dm[[1]]
  }
  
  # NEED refactor the codes----------------------------------------------------
  # group 1 information matrix
  y <- u + v * log(times)
  A <- rbind(rep(0, J), rep(1, J),  log(times))
  p1 <- exp(-exp(y))
  p2 <- exp(y) * p1
  denom <- as.vector(Dm %*% c(1, p1))
  myfun <- function(i, j) sum(Dm[, i + 1] * Dm[, j+1] * p2[i] * p2[j] * prob / denom)
  B <- sapply(1:J, function(x) sapply(1:J, function(y) myfun(x, y)))
  I1 <- A %*% B %*% t(A)
  
  # group 2 information matrix
  a <- log(HR)
  y <- u + a + v * log(times)
  A <- rbind(rep(1, J), rep(1, J),  log(times))
  p1 <- exp(-exp(y))
  p2 <- exp(y) * p1
  denom <- as.vector(Dm %*% c(1, p1))
  myfun <- function(i, j) sum(Dm[, i + 1] * Dm[, j+1] * p2[i] * p2[j] * prob / denom)
  B <- sapply(1:J, function(x) sapply(1:J, function(y) myfun(x, y)))
  I2 <- A %*% B %*% t(A)
  #----------------------------------------------------------------------------
  
  If       <- rho*I1+(1-rho)*I2
  inv.If   <- solve(If)
  beta.var <- inv.If[1]
  
  ## Calculate Sample size or Power
  if (!is.null(power)) {
    N  <- ceiling((qnorm(1-alpha/2)+qnorm(power))^2*beta.var/beta^2)
    N1 <- round(rho*N)
    N2 <- N-N1
    return(list(result=data.frame(N,N1,N2,power), I1=I1, I2=I2))
  } else {
    beta.varN <- beta.var/N
    za    <- qnorm(1-alpha/2)
    zb    <- beta/sqrt(beta.varN)
    power <- pnorm(-za,zb,1)+1-pnorm(za,zb,1)        
    N1 <- round(rho*N)
    N2 <- N-N1        
    return(list(result=data.frame(N,N1,N2,power), I1=I1, I2=I2))
  }
}
