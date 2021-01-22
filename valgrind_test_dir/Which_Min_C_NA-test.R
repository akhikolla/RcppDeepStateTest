function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_Min_C_NA"]][[length(e[["Which_Min_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Which_Min_C_NA", x)
}
