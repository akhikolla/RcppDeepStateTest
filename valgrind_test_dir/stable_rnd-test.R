function (N, pars, parametrization = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_rnd"]][[length(e[["stable_rnd"]]) + 1]] <- list(N = N, 
        pars = pars, parametrization = parametrization)
    .Call("_libstableR_stable_rnd", N, pars, parametrization)
}
