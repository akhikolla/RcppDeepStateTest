#' Plot Peak Ranges of Change Points
#' 
#' Plot the peak ranges of change points produced by \emph{MultiWindow}. 
#' The blue solid line is the start of a peak range and the red dashed line
#' is the end of that peak range.
#' 
#' @references J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change
#'   Point Analysis: Fast Implementation and Strong Consistency}. IEEE
#'   Transactions on Signal Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#'   
#' @param y The original data to find change points. Must be one dimensional
#'   data.
#' @param result The result of function \emph{MultiWindow}.
#' @param ... Arguments to be passed to plot, such as \emph{main, xlab, ylab}.
#'
#' @return A plot of original data and peak ranges of change points.
#' @import graphics
#' @importFrom utils tail
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
#' result <- MultiWindow(y,window_list=c(100,50,20,10,5),point_max=5)
#' ChangePointsPlot(y,result)
 
ChangePointsPlot <- function(y,result, ...) {
  peak_range <- result$peak_range
  plot(y, type="l", ...)
  for (i in 1:length(peak_range)) {
    abline(v=c(peak_range[[i]][1], tail(peak_range[[i]], n=1)), col=c("blue", "red"),lty=c("solid","dashed"))
  }
}
#' Plot score 
#' 
#' Plot the score of each range, which represents how likely the range contains change points.
#' 
#' @references J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change
#'   Point Analysis: Fast Implementation and Strong Consistency}. IEEE
#'   Transactions on Signal Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#'   
#' @param result The result of function \emph{MultiWindow}. The argument \emph{ret_score} of 
#'        \emph{MultiWindow} must be \emph{TRUE}.
#' @param ... Arguments to be passed to plot, such as \emph{main, xlab, ylab}.
#'
#' @return A stair plot of score.
#' @import graphics
#' @export
#'
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
#' result <- MultiWindow(y,window_list=c(100,50,20,10,5),point_max=5,ret_score=TRUE)
#' ScorePlot(result, main="score plot")
ScorePlot <- function(result, ...) {
  score <- result$score
  r <- dim(score)[2]
  score <- score[ ,r]
  plot(score, type="s", ...)
}

