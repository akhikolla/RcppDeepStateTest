function (a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["int_randomShuffle"]][[length(e[["int_randomShuffle"]]) + 
        1]] <- list(a = a)
    .Call("_BoostMLR_int_randomShuffle", a)
}
