function (xs, ys, zs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getVelocities3d"]][[length(e[["getVelocities3d"]]) + 
        1]] <- list(xs = xs, ys = ys, zs = zs)
    .Call("_mousetrap_getVelocities3d", xs, ys, zs)
}
