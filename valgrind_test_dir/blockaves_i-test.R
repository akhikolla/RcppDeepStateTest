function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blockaves_i"]][[length(e[["blockaves_i"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_blockaves_i", x, window)
}
