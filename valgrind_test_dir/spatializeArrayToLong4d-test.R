function (xs, ys, z1s, z2s, n_pts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatializeArrayToLong4d"]][[length(e[["spatializeArrayToLong4d"]]) + 
        1]] <- list(xs = xs, ys = ys, z1s = z1s, z2s = z2s, n_pts = n_pts)
    .Call("_mousetrap_spatializeArrayToLong4d", xs, ys, z1s, 
        z2s, n_pts)
}
