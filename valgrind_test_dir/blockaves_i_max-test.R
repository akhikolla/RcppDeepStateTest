function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blockaves_i_max"]][[length(e[["blockaves_i_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_blockaves_i_max", x, window)
}
