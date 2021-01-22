function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["movingaves_n"]][[length(e[["movingaves_n"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_movingaves_n", x, window)
}
