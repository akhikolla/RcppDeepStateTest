#' Priors
#'
#' Functions designed to be plugged in as \code{log_prior} to \code{\link{make.adeba}}.
#' 
#' @param parameters A data frame containing \code{alpha} and \code{beta} values, 
#'   \code{alpha.range} that specifies sampling density, and \code{log.likelihood}
#'   that contains the unnormalized log likelihood for each
#'   \eqn{(\alpha,\beta)}{(alpha, beta)} pair.
#' @return A vector of log prior values.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @aliases log_prior
#' @rdname log_prior
#' @references A demo explaining how \code{empirical_gaussian_log_prior} was
#'   implemented can be found in
#'   \href{https://github.com/backlin/adeba/blob/master/prior-comparison/empirical_gaussian_demo.Rmd}{this Rmarkdown notebook}.
#' @export
uniform_log_prior <- function(parameters){
    rep(0, nrow(parameters))
}

#' @rdname log_prior
#' @export
jeffreys_log_prior <- function(parameters){
    if(length(unique(parameters$beta)) > 1){
        stop("Jeffreys prior is only implemented for use with a constant beta.")
    }
    -log(parameters$alpha)
}

#' @rdname log_prior
#' @importFrom stats aggregate cov.wt
#' @importFrom mixtools dmvnorm
#' @export
empirical_gaussian_log_prior <- function(parameters){
    weights <- with(
        merge(
            parameters,
            aggregate(alpha ~ beta, parameters, function(x) sum(1/x)),
            by="beta"
        ),
        exp(log.likelihood) / (alpha.x * alpha.y)
    )
    x <- cbind(
        log_alpha = log(parameters$alpha),
        beta = parameters$beta
    )
    hyperparams <- cov.wt(x, wt = weights)
    gaussian_prior <- if(is_constant(parameters$beta)){
        # dmvnorm crashes if beta is any column is constant (singular matrix),
        # so we treat this case separately here.
        dmvnorm(x[,1,drop=FALSE], hyperparams$center[1], hyperparams$cov[1,1])
    } else {
        dmvnorm(x, hyperparams$center, hyperparams$cov)
    }
    log(gaussian_prior)
}

