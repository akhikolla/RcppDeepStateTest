function (xs, ys, zs, n_pts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatializeArray3d"]][[length(e[["spatializeArray3d"]]) + 
        1]] <- list(xs = xs, ys = ys, zs = zs, n_pts = n_pts)
    .Call("_mousetrap_spatializeArray3d", xs, ys, zs, n_pts)
}
