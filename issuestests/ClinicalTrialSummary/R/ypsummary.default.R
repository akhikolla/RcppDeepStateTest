ypsummary.default <- function(time, event, group, tau, alpha = 0.05,
    tie = TRUE, bound = 50, repnum = 2000, ...) {

    y <- as.numeric(time)
    d <- as.numeric(event)
    z <- as.numeric(group)

    n <- length(y)

    if (tie == TRUE) {
        if (length(y) != length(unique(y))) {
            JitterValue <- runif(n, 0, 1e-10)
            y <- y + JitterValue
        }
    }

    o <- order(y)
    oy <- y[o]
    oz <- z[o]
    od <- d[o]

    if (is.null(tau)) {
      stop("Please specify 'tau'.")
    }

    best <- fun_estimate(oy = oy, od = od, oz = oz, bound = bound)

    ahrypt <- fun_ahryptwo(oy = oy, od = od, oz = oz, best = best, tau = tau,
                           alpha = alpha, repnum = repnum)
    ahrf <- fun_ahrf(oy = oy, od = od, oz = oz, best = best, tau = tau,
                     alpha = alpha, repnum = repnum)
    rspypt <- fun_rspypt(oy = oy, od = od, oz = oz, best = best, tau = tau,
                         alpha = alpha, repnum = repnum)
    mdypt <- fun_mdypt(oy = oy, od = od, oz = oz, best = best, tau = tau,
        alpha = alpha, repnum = repnum)
    mrypt <- fun_mrypt(oy = oy, od = od, oz = oz, best = best, tau = tau,
        alpha = alpha, repnum = repnum)

    result <- list()
    result$values <- list(ahrypt = ahrypt, ahrf = ahrf, rspypt = rspypt, mdypt = mdypt, mrypt = mrypt)
    result$alpha <- alpha
    result$tau <- tau
    result$tie <- tie
    result$bound <- bound
    result$repnum <- repnum
    result$call <- match.call()

    class(result) <- "ypsummary"
    result
}
