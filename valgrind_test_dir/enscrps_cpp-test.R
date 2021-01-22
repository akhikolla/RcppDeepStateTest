function (ens, obs, R_new) 
{
    e <- get("data.env", .GlobalEnv)
    e[["enscrps_cpp"]][[length(e[["enscrps_cpp"]]) + 1]] <- list(ens = ens, 
        obs = obs, R_new = R_new)
    .Call("_SpecsVerification_enscrps_cpp", ens, obs, R_new)
}
