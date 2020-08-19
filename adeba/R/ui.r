#' Make ADEBA density estimate
#' 
#' @param data Dataset with examples as rows and dimensions as columns, supplied as
#'   a matrix or something that can be converted to a matrix, like a
#'   \code{vector}, \code{data.frame} or \code{data.table}.
#' @param adaptive Whether to used fixed bandwidths identical for all kernels,
#'   or adaptive bandwidths unique to each kernel. Can also be specified as a
#'   positive integer to iterate beyond the adaptive estimate (see the original
#'   publication).
#' @param beta The level of adaptiveness.
#'   The default value of 0.5 corresponds to Silverman's square root law, which
#'   is suitable for the normal distribution.
#'   Can also be specified as multiple
#'   equispaced values, automatically weighted by the Bayesian machinery
#'   (the equispace requirement is for the integral approximation to hold).
#' @param parallel Whether to use multiple CPU cores for calculation, using
#'   \code{\link[parallel]{mclapply}} and \code{\link[parallel]{mcMap}} of the \code{parallel}
#'   package. To control the number of cores please use the \code{mc.cores}
#'   option. If unset, all cores will be used.
#' @param na.rm Whether to let missing values break execution (\code{FALSE}) or
#'   to remove them from calculations (\code{TRUE}).
#' @param ... Sent to the internal function \code{make.adeba}.
#' @return A density estimate.
#' @example examples/adeba.r
#' @seealso \code{\link{predict.adeba}}, \code{\link{render}}, \code{\link{radeba}}
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @export
adeba <- function(data, adaptive=TRUE, beta=0.5, parallel, na.rm=FALSE, ...){
    if(missing(parallel)){
        parallel <- "parallel" %in% "search" && getOption("mc.cores", 1) > 1
    } else {
        requireNamespace("parallel")
        if(is.null(getOption("mc.cores"))) options(mc.cores = parallel::detectCores())
    }
    f <- make.adeba(data=data, beta=beta, na.rm=na.rm, parallel=parallel, ...)
    for(i in 1:(adaptive+1))
        f <- iterate(f)
    f
}

#' ADEBA estimates
#'
#' Density, distribution, and random generation for ADEBA estimates.
#' Works just like \code{\link{rnorm}}, \code{\link{runif}}, etc.
#'
#' @param n Number of examples to sample.
#' @param object Density estimate.
#' @examples
#' data(faithful)
#' f <- adeba(faithful$eruptions, adaptive=FALSE)
#' f.eruptions <- radeba(1e5, f)
#' hist(f.eruptions, breaks=100, col="skyblue", probability=TRUE)
#' lines(f, lwd=3)
#' rug(faithful$eruptions)
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @importFrom stats rnorm
#' @export
radeba <- function(n, object){
    i <- sample(nrow(object$data), n, replace=TRUE)
    k <- sample(nrow(object$parameters), n, replace=TRUE,
                prob = object$parameters$posterior)
    x <- matrix(rnorm(n*dimension(object), mean = object$data[i,],
                      sd = rep(object$bandwidths[cbind(i, k)], dimension(object))),
                nrow=n, ncol=dimension(object))
    object$retransform(x)
}

#' @param x,q Vector of quantiles.
#' @rdname radeba
#' @export
dadeba <- function(x, object){
    predict(object, x)
}
#' @param lower.tail Logical; If \code{TRUE} (default), probabilities are
#'   \eqn{P[X \le x]}, otherwise, \eqn{P[X > x]}.
#' @rdname radeba
#' @importFrom stats pnorm
#' @export
padeba <- function(q, object, lower.tail=TRUE){
    stopifnot(dimension(object) == 1)
    myq <- if(is.vector(q)) matrix(q) else q
    stopifnot(ncol(myq) == 1)
    
    distance <- rep(1, dim(object)[1]) %*% t(myq) - as.vector(object$data)

    bw.fun <- function(bw){
        colMeans(pnorm(distance, sd=bw, lower.tail=lower.tail))
    }
    if(object$parallel){
        requireNamespace("parallel")
        fx.bw <- parallel::mclapply(object$bandwidths, bw.fun)
    } else {
        fx.bw <- lapply(object$bandwidths, bw.fun)
    }
    Reduce("+", Map("*", fx.bw, object$parameters$posterior))
}


#' Retrieve the dimension or dimensions of the dataset used to make the estimate
#' 
#' @param x Density estimate.
#' @return Integer scalar.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @export
dimension <- function(x)
    ncol(x$data)
#' @return Integer vector.
#' @rdname dimension
#' @export
dim.adeba <- function(x)
    dim(x$data)

#' Render and store the estimate
#'
#' @param object Density estimate.
#' @param grid A list of numerical vectors corresponding to the dimensions of
#'   the estimate.
#' @return Nothing, the object is modified in place.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @seealso is.rendered
#' @export
render <- function(object, grid){
    if(missing(grid)){
        grid <- lapply(as.data.frame(apply(object$retransform(object$data), 2, range)),
            function(r){
                margin <- .7*diff(r)
                seq(r[1]-margin, r[2]+margin,
                    length.out = c(200, 50, 20)[min(dimension(object), 3)])
            }
        )
    }
    if(is.numeric(grid)) grid <- list(grid)
    x <- as.matrix(do.call(expand.grid, grid))
    object$grid <- grid
    object$posterior <- array(predict(object, grid), sapply(grid, length))
    object
}

#' Determines if an estimate is rendered
#'
#' @param object Density estimate.
#' @return Logical.
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @seealso render
#' @export
is.rendered <- function(object){
    all(c("grid", "posterior") %in% ls(object))
}

#' @param x Density estimate.
#' @param ... Ignored, kept for S3 consistency.
#' @export
#' @noRd
print.adeba <- function(x, ...){
    yn <- function(x) if(x) "Yes" else "No"
    cat(sprintf("ADBEA estimate.
   Dimension: %i
        Size: %i
    Adaptive: %s (%i iterations)
    Rendered: %s\n", dimension(x), dim(x)[1],
        yn(x$iterations > 1),
        x$iterations, yn(is.rendered(x))))
}

