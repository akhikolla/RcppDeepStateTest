#' Plot density estimate
#' 
#' @method plot adeba
#' @param x Density estimate.
#' @param y Ignored, kept for S3 consistency.
#' @param type What type of plot to draw.
#' @param ... Sent to \code{\link{plot}}, \code{\link{image}} or some other
#'   base plotting function, depending on \code{type} and dimension of the
#'   estimate.
#' @param add Whether to start a new plot (\code{FALSE}) or add to an existing
#'   (\code{TRUE}).
#' @author Christofer \enc{Bäcklin}{Backlin}
#' @importFrom graphics lines plot rug image points
#' @export
plot.adeba <- function(x, y, type=c("estimate", "data", "both"), ..., add=FALSE){
    if(!is.rendered(x)){
        if(dimension(x) > 2)
            stop("Estimates of dimension 3 or higher must be manually sliced before plotting.")
        x <- render(x)
    }
    slice <- which(sapply(x$grid, length) > 1)
    if(length(slice) > 2)
        stop("Only slices of dimension 1 or 2 can be plotted")
    type <- match.arg(type)
    if(type %in% c("estimate", "both")){
        if(length(slice) == 1){
            if(add) lines(x$grid[[1]], x$posterior, ...)
            else plot(x$grid[[1]], x$posterior, type="l", ...)
        } else {
            image(x$grid[[1]], x$grid[[2]], x$posterior, ...)
        }
    }
    add <- add || type %in% "both"
    if(type %in% c("data", "both")){
        data <- x$retransform(x$data)
        if(length(slice) == 1){
            if(add) rug(data[,slice], ...)
            else plot(data[,slice], ...)
        } else {
            if(add) points(data[,slice[1]], data[,slice[2]], ...)
            else plot(data[,slice[1]], data[,slice[2]], ...)
        }
    }
}

#' @method lines adeba
#' @rdname plot.adeba
#' @export
lines.adeba <- function(x, ...){
    if(!is.rendered(x)){
        if(dimension(x) > 2)
            stop("Estimates of dimension 3 or higher must be manually sliced before plotting.")
        x <- render(x)
    }
    lines(x = x$grid[[1]], y = x$posterior, ...)
}

#' @method points adeba
#' @rdname plot.adeba
#' @importFrom graphics rug
#' @importFrom stats approx
#' @export
points.adeba <- function(x, ...){
    if(!is.rendered(x)){
        if(dimension(x) > 2)
            stop("Estimates of dimension 3 or higher must be manually sliced before plotting.")
        x <- render(x)
    }
    data <- x$retransform(x$data)
    if(dimension(x) == 1){
        points(approx(x$grid[[1]], x$posterior, data), ...)
    } else if(dimension(x) == 2){
        points(x = data[,1], y = data[,2], ...)
    } else {
        stop("Only estimates of dimension 1 and 2 can be plotted with `points`.")
    }
}

#' @method contour adeba
#' @rdname plot.adeba
#' @importFrom graphics contour
#' @export
contour.adeba <- function(x, ...){
    if(!is.rendered(x)){
        if(dimension(x) > 2)
            stop("Estimates of dimension 3 or higher must be manually sliced before plotting.")
        x <- render(x)
    }
   contour(x$grid[[1]], x$grid[[2]], x$posterior, ...)
}

