function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["movingaves_n_max"]][[length(e[["movingaves_n_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_movingaves_n_max", x, window)
}
