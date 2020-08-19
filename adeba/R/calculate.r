#' @useDynLib adeba, .registration=TRUE
#' @importFrom Rcpp evalCpp
NULL

#' Initialize a density estimate
#' 
#' @param data Dataset.
#' @param range Domain of each variable (column) of the dataset.
#'   The idea is to allow for bounded kernels in the future, but at the moment
#'   this argument has no effect.
#' @param alpha Alpha values controlling the global bandwidth scaling.
#'   This should be set to \code{NULL}, implying automatic estimation from the
#'   data, unless you know what you are doing.
#' @param beta See \code{\link{adeba}}.
#' @param pilot Pilot function values for the first iteration. Leave unspecified
#'   to use a constant pilot.
#' @param transform If estimating multivariate densities, this argument controls
#'   whether the dataset should be pre-rotated and scaled before estimation.
#'   If the covariance matrix of \code{data} is large this is a very good idea,
#'   but it takes a litte extra time to do.
#' @param na.rm Whether to remove observations with missing values (\code{TRUE})
#'   or throw an error (\code{FALSE}).
#' @param parallel See \code{\link{adeba}}.
#' @param log_prior A function that calculates a log prior from a data frame
#'   with parameters. See \code{\link{log_prior}} for options and details.
#'
#'   \emph{NOTE:}\cr
#'   Unless you know ADEBAs internals well you should probably not
#'   touch this argument. It was only exposed to facilitate analyses on the
#'   prior's importance, or rather lack of it, which were added as a supplement
#'   to the original publication.
#' @return An unfitted density estimate that it to be passed to
#'   \code{\link{iterate}}.
#'   The estimate consist of the following components:
#'   \describe{
#'     \item{\code{iterations}}{Number of iterations calculated.}
#'     \item{\code{parameters}}{All the parameters and posterior values.}
#'     \item{\code{bandwidths}}{Bandwidths corresponding to the parameters.
#'       These are pre-calculated to make the results easier for the user to
#'       digest and manipulate, and since are often needed multiple times.}
#'     \item{\code{distance}}{Distance matrix of the original data set.}
#'     \item{\code{constant}}{Logical vector marking columns in the data set
#'       without any variation. These are excluded from the analysis.}
#'     \item{\code{transform}}{To be able to use spherical kernels on
#'       multivariate data sets with variables of very different variances or
#'       high linear dependence, a PCA-based transformation is applied to the
#'       data prior to computation. This element contains that function.}
#'     \item{\code{retransform}}{Function for converting transformed data back
#'       to the original domain. Needed by \code{\link{radeba}}.}
#'   }
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @importFrom pdist pdist
#' @importFrom stats predict complete.cases prcomp dist
#' @export
make.adeba <- function(data, range=c(Inf, Inf), alpha=NULL, beta=0.5, pilot,
                       transform=TRUE, na.rm=FALSE, parallel=FALSE, log_prior=uniform_log_prior){
    # Check data set
    stopifnot(is.numeric(data))
    if(!is.matrix(data)) data <- as.matrix(data)
    cc <- complete.cases(data)
    if(any(!cc)){
        if(na.rm){
            data <- data[cc,,drop=FALSE]
        } else {
            stop("Data set contains missing values. Fix or run with `na.rm=TRUE`.")
        }
    }

    # Find variables with no variation
    constant <- find_constants(data)
    if(all(constant)){
        stop("The dataset does not contain any variation.")
    } else if(any(constant)){
        warning(sprintf("%i columns contain no variation. These will be ignored.",
                        sum(constant)))
        data <- data[, !constant, drop=FALSE]
    }

    # Set up transform
    transform_fun <- retransform_fun <- identity
    scale_factor <- 1
    if(transform){
        if(ncol(data) == 1){
            if(is.infinite(range[1])){
                if(!is.infinite(range[2])){
                    transform_fun <- function(x) -x - range[1]
                    retransform_fun <- function(x) -x + range[1]
                }
            } else {
                if(is.infinite(range[2])){
                    transform_fun <- function(x) x - range[1]
                    retransform_fun <- function(x) x + range[1]
                } else {
                    transform_fun <- function(x) (x - range[1])/diff(range)
                    retransform_fun <- function(x) diff(range)*x + range[1]
                    scale_factor <- 1/diff(range)
                }
            }
            data <- transform_fun(data)
        } else {
            rotation <- prcomp(data, scale.=FALSE)
            data <- scale(rotation$x, center=FALSE)
            rotation$x <- NULL # No point in keeping an extra copy of the dataset
            transform_fun <- function(x)
                sweep(predict(rotation, x), 2, attr(data, "scaled:scale"), "/")
            retransform_fun <- function(x)
                scale(sweep(x, 2, attr(data, "scaled:scale"), "*") %*% solve(rotation$rotation),
                      -rotation$center, FALSE)
            scale_factor <- 1/prod(attr(data, "scaled:scale"))
        }
    }

    structure(class = "adeba", .Data = list(
        data = data,
        constant = constant,
        transform = transform_fun,
        retransform = retransform_fun,
        scale_factor = scale_factor,
        distance = as.matrix(dist(data)),
        iterations = 0,
        alpha = alpha,
        beta = beta,
        pilot = if(missing(pilot)) rep(1, nrow(data)) else pilot,
        parameters = NULL,
        bandwidths = NULL,
        parallel = parallel,
        log_prior = log_prior
    ))
}

#' Fit parameters
#' 
#' This function finds appropriate values for alpha, using a fixed beta=0.5, and
#' calculates the estimate.
#' 
#' To identify a suitable range for alpha containing the bulk of its posterior
#' probability, a rough logarithmically spaced grid is searched.
#' The returned interval is searched again to yield more accurate endpoints,
#' and finally a fine linearly spaced grid is used for the final density
#' estimate.
#' 
#' @param object Density estimate.
#' @param ... Sent to the internal function \code{get_log_likelihood}.
#' @return An ADEBA estimate with increased number of iterations.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @export
iterate <- function(object, ...){
    if(object$iterations > 0)
        object$pilot <- predict(object) # Update pilot
    if(is_constant(object$pilot)){
        parameters <- list(get_log_likelihood(object, alpha=object$alpha, beta=0, ...))
    } else {
        parameters <- lapply(object$beta, function(b){
            get_log_likelihood(object, alpha=object$alpha, beta=b, ...)
        })
    }
    object$parameters <- normalize_posterior(parameters, object$log_prior)
    if(nrow(object$parameters) == 1){
        object$bandwidths <- with(object, data.frame(X1 = parameters$alpha/pilot^parameters$beta))
    } else {
        object$bandwidths <- as.data.frame(t(vapply(object$pilot, function(x)
            FUN = object$parameters$alpha/x^object$parameters$beta,
            FUN.VALUE = object$parameters$alpha)))
    }
    object$iterations <- object$iterations + 1
    object
}

#' Get likelihood given beta
#' 
#' Given a value of the beta parameter this function will first identify a
#' suitable range for the alpha parameter by calculating the likelihood over a
#' logarithmically distributed rough grid.
#' The range in which the likelihood is not very small will be selected,
#' and the likelihood will be recalculated over a finer linear grid.
#' 
#' @param object Adeba estimate containing a pilot.
#' @param alpha Range of alpha values to use. If missing grid search will be
#'   performed (controlled with the \code{rough} and \code{fine} arguments).
#' @param beta Beta value to use.
#' @param rough Rough search grid resolution.
#' @param fine Fine search grid resolution.
#' @return A data frame with values for alpha, beta, and the log likelihood
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @importFrom stats dnorm
#' @noRd
get_log_likelihood <- function(object, alpha, beta=0.5, rough=11, fine=41){
    k <- dimension(object)
    stopifnot(length(beta) == 1)

    # Run likelihood calculation in parallel if possible
    my.sapply <- if(object$parallel){
        function(...) unlist(parallel::mclapply(...))
    } else {
        sapply
    }

    # Calculate log likelihood probabilities
    #
    # @param bandw A data frame of bandwidths where the rows represent
    #   observations in the data set and the columns represent different hyper
    #   parameter choices.
    # @return A vector of likelihood, one value for each column in \code{bandw}.
    log.likelihood <- function(bandw){
        my.sapply(bandw, function(bw){
            kd <- dnorm(object$distance, sd=bw)/((2*pi)^((k-1)/2)*bw^(k-1))
            diag(kd) <- NA
            sum(log10(apply(kd, 1, mean, na.rm=TRUE)))
        })
    }

    if(missing(alpha) || is.null(alpha)){
        # Rough tune alpha twice in logarithmic space
        log.range <- c(-6, 3)
        for(r in 1:2){
            alpha <- 10^seq(log.range[1], log.range[2], length.out=rough)
            bandwidths <- data.frame((1/object$pilot^beta) %*% t(alpha))
            likelihood <- log.likelihood(bandwidths)
            i <- range(which(likelihood >= max(likelihood)-3))
            if(any(c(1, rough) %in% i))
                warning("Rough alpha range not large enough.")
            log.range <- log10(alpha)[c(max(1, i[1]-1), min(rough, i[2]+1))]
        }
        # Fine tune alpha in linear space
        alpha <- seq(10^log.range[1], 10^log.range[2], length.out=fine)
    }

    bandwidths <- data.frame((1/object$pilot^beta) %*% t(alpha))
    data.frame(alpha = alpha,
               beta = beta,
               log.likelihood = log.likelihood(bandwidths))
}

#' Normalize posteriors obtained for different beta
#'
#' This function adjusts the posterior values returned from
#' \code{get_log_likelihood} based on how densely the alpha values were
#' sampled for each beta value. 
#' This must be done in order for the integral approximation to work,
#' otherwise small beta will be given far too much influence.
#'
#' @param parameters List of parameter and likelihood estimates as returned by
#'   \code{get_log_likelihood}.
#' @param A single merged data frame containing all parameters and posteriors
#'   for all tested values of alpha and beta.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @noRd
normalize_posterior <- function(parameters, log_prior=uniform_log_prior){
    beta <- sapply(parameters, function(x) x$beta[1])
    if(length(beta) > 2){
        local({
            beta.diff <- diff(beta)
            if(any(abs(beta.diff - beta.diff[1]) > 1e-9))
                stop("The beta values are not linearly distributed.")
        })
    }

    # Multiply the likelihood with this factor to compensate for the density of the alpha values.
    alpha.range <- sapply(parameters, function(x) diff(range(x$alpha)))
    if(all(alpha.range == 0)){
        # Effectively remove the alpha range from the calculation
        alpha.range <- rep(1, length(alpha.range))
    } else if(any(alpha.range == 0)){
        # This shouldn't ever happen, but just to be safe
        stop("Cannot normalize posterior since some beta values have only a single alpha value.")
    }

    parameters <- do.call(rbind, Map(function(p, ar){
        p$alpha.range <- ar
        p
    }, parameters, alpha.range))

    parameters$log.prior <- log_prior(parameters)

    # Multiply the likelihood with this factor to not fall beneth computational precision.
    # This is typically a large negative value.
    shift <- max(parameters$log.likelihood)

    posterior <- with(parameters,
        exp(log.likelihood - shift + alpha.range + log.prior))
    parameters$posterior <- posterior/sum(posterior)
    parameters
}

#' Predict PDF at selected points
#' 
#' @param object Density estimate.
#' @param newx New data points to predict. Can either be a dataset of the same
#'   dimension as was used to make the estimate, or a point grid in list form
#'   (see \code{\link{render}} for details).
#' @param ... Ignored, kept for S3 consistency.
#' @return A vector if \code{newx} is a matrix or array, or an array if
#'   \code{newx}.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @export
predict.adeba <- function(object, newx, ...){
    if(missing(newx)){
        x <- object$data
        distance <- object$distance
    } else {
        if(is.list(newx)){
            stopifnot(length(newx) == length(object$constant))
            x <- as.matrix(do.call(expand.grid, newx))
        } else {
            stopifnot(is.numeric(newx))
            x <- newx
            if(!is.matrix(x)) x <- as.matrix(x)
            stopifnot(ncol(x) == length(object$constant))
        }
        if(any(object$constant))
            x <- x[, !object$constant, drop=FALSE]
        x <- object$transform(x)
        distance <- as.matrix(pdist(object$data, x))
    }
    k <- dimension(object)
    bw.fun <- function(bw){
        colMeans(dnorm(distance, sd=bw)/((2*pi)^((k-1)/2)*bw^(k-1)))
    }
    if(object$parallel){
        requireNamespace("parallel")
        fx.bw <- parallel::mclapply(object$bandwidths, bw.fun)
    } else {
        fx.bw <- lapply(object$bandwidths, bw.fun)
    }
    fx <- Reduce("+", Map("*", fx.bw, object$parameters$posterior))
    object$scale_factor*fx
}

