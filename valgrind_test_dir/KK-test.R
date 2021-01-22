function (x, type) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KK"]][[length(e[["KK"]]) + 1]] <- list(x = x, type = type)
    .Call("_highfrequency_KK", x, type)
}
