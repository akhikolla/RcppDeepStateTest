function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["select_max"]][[length(e[["select_max"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_mousetrap_select_max", x, y)
}
