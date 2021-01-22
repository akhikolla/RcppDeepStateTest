function (x, pi, mulog, sdlog, max_iter = 500L, tol = 1e-06) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lnorm_C"]][[length(e[["lnorm_C"]]) + 1]] <- list(x = x, 
        pi = pi, mulog = mulog, sdlog = sdlog, max_iter = max_iter, 
        tol = tol)
    .Call("_mixR_lnorm_C", x, pi, mulog, sdlog, max_iter, tol)
}
