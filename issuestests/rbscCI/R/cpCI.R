#' Clopper-Pearson confidence interval
#' 
#' @details Computes the Clopper-Pearson confidence interval.
#'
#' @param n_tot Total number of experiments
#' @param n_suc Number of successes
#' @param conf Confidence level (1-alpha)
#' @param digits Number of decimal places to be used
#' 
#' @examples cpCI(100,25,0.95)
#'
#' @export cpCI
cpCI <- function(n_tot, n_suc, conf, digits = 2) {
  
  stopifnot(n_tot >= 0 && n_suc >= 0 && n_tot >= n_suc)
  stopifnot(conf > 0 && conf < 1)
  
  cp_ci <- .cpCI(n_tot, n_suc, conf)
  
  if (!missing(digits)) {
    round(cp_ci, digits)
  }
  else {
    return(cp_ci)
  }
}
