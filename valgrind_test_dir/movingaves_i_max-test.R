function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["movingaves_i_max"]][[length(e[["movingaves_i_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_movingaves_i_max", x, window)
}
