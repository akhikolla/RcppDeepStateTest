function (xs, ys, zs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getLengths3d"]][[length(e[["getLengths3d"]]) + 1]] <- list(xs = xs, 
        ys = ys, zs = zs)
    .Call("_mousetrap_getLengths3d", xs, ys, zs)
}
