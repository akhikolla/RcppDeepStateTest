function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_Max_C"]][[length(e[["Which_Max_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Which_Max_C", x)
}
