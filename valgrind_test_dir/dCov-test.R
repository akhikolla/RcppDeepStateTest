function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dCov"]][[length(e[["dCov"]]) + 1]] <- list(x = x, y = y)
    .Call("_MESS_dCov", x, y)
}
