function (x, y, proc = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mi"]][[length(e[["mi"]]) + 1]] <- list(x = x, y = y, 
        proc = proc)
    .Call("_BNSL_mi", x, y, proc)
}
