function (xs, ys, zs, n_pts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatializeArrayToLong3d"]][[length(e[["spatializeArrayToLong3d"]]) + 
        1]] <- list(xs = xs, ys = ys, zs = zs, n_pts = n_pts)
    .Call("_mousetrap_spatializeArrayToLong3d", xs, ys, zs, n_pts)
}
