function (fcst, obs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["auc_cpp"]][[length(e[["auc_cpp"]]) + 1]] <- list(fcst = fcst, 
        obs = obs)
    .Call("_SpecsVerification_auc_cpp", fcst, obs)
}
