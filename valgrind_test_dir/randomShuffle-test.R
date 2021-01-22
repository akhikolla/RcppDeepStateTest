function (a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["randomShuffle"]][[length(e[["randomShuffle"]]) + 1]] <- list(a = a)
    .Call("_BoostMLR_randomShuffle", a)
}
