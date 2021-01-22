function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getLength"]][[length(e[["getLength"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_mousetrap_getLength", x, y)
}
