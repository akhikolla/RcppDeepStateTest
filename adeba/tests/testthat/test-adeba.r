context("Algorithm")

test_that("Expected behaviour", {
    x <- matrix(rnorm(50, mean=3, sd=2), nrow=25, ncol=2)
    f <- adeba(x, adaptive=TRUE, beta=0:4/2, parallel = FALSE)

    # Check parameter estimation
    expect_lt(abs(sum(f$parameters$posterior) - 1), 1e-12)

    # Check that pdf volume ~= 1
    # A small amount of probability mass will inevitably be located outside the
    # grid area causing the volume to be slightly less than 1.
    f <- render(f)
    dg <- prod(sapply(f$grid, diff)[1,])
    volume <- sum(dg*f$posterior)
    expect_lt(volume, 1)
    expect_gt(volume, .97) # Some of the volume is outside of the grid

    # Parallelization
    require(parallel)
    options(mc.cores = 2)
    f.parallel <- render(adeba(x, beta=0:4/2, parallel=TRUE))
    expect_identical(f.parallel$parameters, f$parameters)
})

test_that("Posterior calculation", {
    x <- rnorm(20)

    obj1 <- make.adeba(x)
    obj1 <- iterate(obj1)

    obj2 <- list(data = matrix(x),
                 distance = as.matrix(dist(x)),
                 parallel = FALSE,
                 pilot = rep(1, 20))
    parameters <- get_log_likelihood(obj2, beta=0)
    expect_is(parameters, "data.frame")
    expect_true(all(c("alpha", "beta", "log.likelihood") %in% names(parameters)))

    parameters <- normalize_posterior(list(parameters))
    expect_equal(sum(parameters$posterior), 1, tolerance=1e-3)
    expect_equal(parameters, obj1$parameters, tolerance=1e-3)
    # The tolerance is deliberately set high since we have no idea what CPU
    # might run the code.
})

test_that("Cumulative distribution function", {
    x <- c(rnorm(20), rnorm(20, mean=2, sd=.5))
    den <- adeba(x)
    q <- seq(-5, 5, length.out = 1000)
    dq <- dadeba(q, object = den)
    cdq <- cumsum(dq)/sum(dq)
    pq <- padeba(q, object = den)
    expect_true(all(abs(pq - cdq) < .01))
})

