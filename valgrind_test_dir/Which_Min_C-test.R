function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_Min_C"]][[length(e[["Which_Min_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Which_Min_C", x)
}
