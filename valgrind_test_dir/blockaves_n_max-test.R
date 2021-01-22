function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blockaves_n_max"]][[length(e[["blockaves_n_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_blockaves_n_max", x, window)
}
