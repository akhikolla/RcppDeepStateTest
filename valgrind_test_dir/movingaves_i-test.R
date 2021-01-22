function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["movingaves_i"]][[length(e[["movingaves_i"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_movingaves_i", x, window)
}
