function (obs, pi0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FindCayley"]][[length(e[["FindCayley"]]) + 1]] <- list(obs = obs, 
        pi0 = pi0)
    .Call("_rankdist_FindCayley", obs, pi0)
}
