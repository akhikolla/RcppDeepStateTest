function (data, pi, mulog, sdlog, max_iter = 500L, tol = 1e-06) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lnorm_g_C"]][[length(e[["lnorm_g_C"]]) + 1]] <- list(data = data, 
        pi = pi, mulog = mulog, sdlog = sdlog, max_iter = max_iter, 
        tol = tol)
    .Call("_mixR_lnorm_g_C", data, pi, mulog, sdlog, max_iter, 
        tol)
}
