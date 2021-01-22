function (rnd, pars_init = as.numeric(c()), parametrization = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_fit_koutrouvelis"]][[length(e[["stable_fit_koutrouvelis"]]) + 
        1]] <- list(rnd = rnd, pars_init = pars_init, parametrization = parametrization)
    .Call("_libstableR_stable_fit_koutrouvelis", rnd, pars_init, 
        parametrization)
}
