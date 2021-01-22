function (rnd, pars_init = as.numeric(c()), parametrization = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_fit_mle"]][[length(e[["stable_fit_mle"]]) + 1]] <- list(rnd = rnd, 
        pars_init = pars_init, parametrization = parametrization)
    .Call("_libstableR_stable_fit_mle", rnd, pars_init, parametrization)
}
