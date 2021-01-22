function (rnd, pars_init = as.numeric(c()), parametrization = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_fit_mle2d"]][[length(e[["stable_fit_mle2d"]]) + 
        1]] <- list(rnd = rnd, pars_init = pars_init, parametrization = parametrization)
    .Call("_libstableR_stable_fit_mle2d", rnd, pars_init, parametrization)
}
