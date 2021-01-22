function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getLength3d"]][[length(e[["getLength3d"]]) + 1]] <- list(x = x, 
        y = y, z = z)
    .Call("_mousetrap_getLength3d", x, y, z)
}
