function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getVelocity3d"]][[length(e[["getVelocity3d"]]) + 1]] <- list(x = x, 
        y = y, z = z)
    .Call("_mousetrap_getVelocity3d", x, y, z)
}
