function (ens, obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EnsRocaCpp"]][[length(e[["EnsRocaCpp"]]) + 1]] <- list(ens = ens, 
        obs = obs)
    .Call("_easyVerification_EnsRocaCpp", ens, obs)
}
