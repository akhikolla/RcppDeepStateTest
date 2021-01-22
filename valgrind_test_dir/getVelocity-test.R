function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getVelocity"]][[length(e[["getVelocity"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_mousetrap_getVelocity", x, y)
}
