function (p, pars, parametrization = 0L, tol = 1e-12) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_q"]][[length(e[["stable_q"]]) + 1]] <- list(p = p, 
        pars = pars, parametrization = parametrization, tol = tol)
    .Call("_libstableR_stable_q", p, pars, parametrization, tol)
}
