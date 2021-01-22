function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getAngleV"]][[length(e[["getAngleV"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_mousetrap_getAngleV", x, y)
}
