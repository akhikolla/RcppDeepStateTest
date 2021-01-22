function (rnd, parametrization = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_fit_init"]][[length(e[["stable_fit_init"]]) + 
        1]] <- list(rnd = rnd, parametrization = parametrization)
    .Call("_libstableR_stable_fit_init", rnd, parametrization)
}
