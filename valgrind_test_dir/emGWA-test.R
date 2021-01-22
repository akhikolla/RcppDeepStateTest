function (y, gen) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emGWA"]][[length(e[["emGWA"]]) + 1]] <- list(y = y, gen = gen)
    .Call("_NAM_emGWA", y, gen)
}
