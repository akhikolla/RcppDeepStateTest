function (x, pars, parametrization = 0L, tol = 1e-12) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_cdf"]][[length(e[["stable_cdf"]]) + 1]] <- list(x = x, 
        pars = pars, parametrization = parametrization, tol = tol)
    .Call("_libstableR_stable_cdf", x, pars, parametrization, 
        tol)
}
