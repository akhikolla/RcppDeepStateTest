function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Which_Max_Matrix"]][[length(e[["Which_Max_Matrix"]]) + 
        1]] <- list(x = x)
    .Call("_BoostMLR_Which_Max_Matrix", x)
}
