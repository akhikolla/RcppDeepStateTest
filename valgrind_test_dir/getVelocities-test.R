function (xs, ys) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getVelocities"]][[length(e[["getVelocities"]]) + 1]] <- list(xs = xs, 
        ys = ys)
    .Call("_mousetrap_getVelocities", xs, ys)
}
