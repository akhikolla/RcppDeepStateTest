#' Estimate Coefficients
#'
#' Transform N dependent data into approximated independent data (N/window_size) x (L+1).
#' Computes the estimated coefficients of each window of original data.
#'
#' @references
#' J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
#' Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
#' Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#' @param y The original data to find change points.
#' @param window_size The number of observations each window contains.
#' @import stats
#' @return
#'   \item{x}{The transformed data, which are the estimated coefficients of original data.}
#' @export
#' @examples
#' N <- 1000
#' N1 <- floor(0.1*N)
#' N2 <- floor(0.3*N)
#' a1 <- c(0.8, -0.3); c1 <- 0
#' a2 <- c(-0.5, 0.1); c2 <- 0
#' a3 <- c(0.5, -0.5); c3 <- 0
#' y <- rep(0,N)
#' L<-2
#' y[1:L] <- rnorm(L)
#' for (n in (L+1):N){
#'   if (n <= N1) {
#'     y[n] <- y[(n-1):(n-L)] %*% a1 + c1 + rnorm(1)
#'   } else if (n <= (N1+N2)) {
#'     y[n] <- y[(n-1):(n-L)] %*% a2 + c2 + rnorm(1)
#'   }
#'   else {
#'     y[n] <- y[(n-1):(n-L)] %*% a3 + c3 + rnorm(1)
#'   }
#' }
#' GetMle(y,window_size=100)
GetMle<- function(y, window_size) {
  N <- length(y)
  n_window <- ceiling(N/window_size)
  L <- 2 # Lag order of the dataset
  #x <- matrix(0, nrow = n_window, ncol = L+1)
  EstimateAr <- function(x,T1,T2,L){
    if (T1 > (T2 - L)) {
      stop("Lag is too big")
    }
    if (T1 <= L) {
      T1 <- L + 1
    }
    Y <- matrix(0, nrow=L+1, ncol=T2-T1+1)
    Y[1,] <- 1
    for (k in 1:L) {
      Y[k+1, ] <- x[(T1-k):(T2-k)]
    }
    A <- Y%*%t(Y)
    B <- Y%*%x[T1:T2]
    C <- solve(A)%*%B
    e <- x[T1:T2]-t(Y)%*%C
    sigma2 <- sum(e^2)/(T2-T1+1)
    est_coef <- list(C=C,sigma2=sigma2)
    return(est_coef)
  }
  for (n in 1:n_window) {
    #test
    #test
    #get estimated coefficients including constant
    T1 <- 1+(n-1)*window_size
    T2 <- min(n*window_size,N)
    if (n == (n_window - 1)) {
      T1_next <- 1+n * window_size
      T2_next <- min((n + 1) * window_size, N)
      if (T1_next > (T2_next - L)) {
        est <- EstimateAr(y,1+(n-1)*window_size, N, L)
        if (n==1) {
          x <- t(est$C)
        } else {
          x <- rbind(x,t(est$C))
        }
        break
      }
    }
    est <- EstimateAr(y,1+(n-1)*window_size,min(n*window_size,N),L)
    #transform original data to transformed data which is the estimated coefficients
    if (n==1) {
      x <- t(est$C)
    } else {
      x <- rbind(x,t(est$C))
    }
  }
  return(x)
}

#' Estimate Coefficients using ar Function
#'
#' Transform N dependent data into approximated independent data (N/window_size) x (L+1).
#' Computes the estimated coefficients of each window of original data.
#'
#' @references
#' J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
#' Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
#' Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#' @param y The original data to find change points.
#' @param window_size The number of observations each window contains.
#'
#' @return
#'   \item{x}{The transformed data, which are the estimated coefficients of original data.}
#' @export
#' @examples
#' N = 1000
#' N1 = floor(0.1*N)
#' N2 = floor(0.3*N)
#' a1 = c(0.8, -0.3); c1 = 0
#' a2 = c(-0.5, 0.1); c2 = 0
#' a3 = c(0.5, -0.5); c3 = 0
#' y = rep(0,N)
#' L=2
#' y[1:L] = rnorm(L)
#' for (n in (L+1):N){
#'   if (n <= N1) {
#'     y[n] = y[(n-1):(n-L)] %*% a1 + c1 + rnorm(1)
#'   } else if (n <= (N1+N2)) {
#'     y[n] = y[(n-1):(n-L)] %*% a2 + c2 + rnorm(1)
#'   }
#'   else {
#'     y[n] = y[(n-1):(n-L)] %*% a3 + c3 + rnorm(1)
#'   }
#' }
#' GetMleAr(y,window_size=100)
GetMleAr <- function(y, window_size) {
  N <- length(y)
  n_window <- ceiling(N/window_size)
  L <- 1 # Lag order of the dataset
  x <- matrix(0, nrow = n_window, ncol = L+1)
  for (n in 1:n_window) {
    #test
    #test
    #get estimated coefficients including constant
    est <- stats::ar(y[(1 + (n - 1) * window_size):min(n * window_size, N)], aic = FALSE, order.max = L, method = "ols")
    x[n, 1] <- est$x.intercept
    x[n, 2:(L + 1)] <- est$ar
    #    if (method == "ols") {
    #      est<-ar(y[(1+(n-1)*window_size):min(n*window_size,N)],aic=FALSE,order.max = L,method="ols")
    #      x[n,1]<-est$x.intercept
    #      x[n,2:(L+1)]<-est$ar
    #    }
    #    if (method == "mle") {
    #      est<-ar(x[(1+(n-1)*window_size):min(n*window_size,N)],aic=FALSE,order.max = L,method="mle")
    #      x_transformed[n,1]<-est$x.mean
    #      x_transformed[n,2:(L+1)]<-est$ar
    #    }
    #    if ((method == "yule-walker") || (method == "yw")) {
    #      est<-ar(x[(1+(n-1)*window_size):min(n*window_size,N)],aic=FALSE,order.max = L,method="yule-walker")
    #      x_transformed[n,1]<-est$x.mean
    #      x_transformed[n,2:(L+1)]<-est$ar
    #    }
  }
  return(x)
}

