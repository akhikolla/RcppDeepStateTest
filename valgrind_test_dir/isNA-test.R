function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["isNA"]][[length(e[["isNA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_isNA", x)
}
