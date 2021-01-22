function (obs, pi0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Wtau"]][[length(e[["Wtau"]]) + 1]] <- list(obs = obs, 
        pi0 = pi0)
    .Call("_rankdist_Wtau", obs, pi0)
}
