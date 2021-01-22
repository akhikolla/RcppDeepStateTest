function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blockaves_n"]][[length(e[["blockaves_n"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_blockaves_n", x, window)
}
