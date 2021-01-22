function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_Max_C_NA"]][[length(e[["Which_Max_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Which_Max_C_NA", x)
}
