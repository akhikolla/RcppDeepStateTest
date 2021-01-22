function (obs, pi0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FindV"]][[length(e[["FindV"]]) + 1]] <- list(obs = obs, 
        pi0 = pi0)
    .Call("_rankdist_FindV", obs, pi0)
}
