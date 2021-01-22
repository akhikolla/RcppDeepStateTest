function (x, x_set) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_C"]][[length(e[["Which_C"]]) + 1]] <- list(x = x, 
        x_set = x_set)
    .Call("_BoostMLR_Which_C", x, x_set)
}
