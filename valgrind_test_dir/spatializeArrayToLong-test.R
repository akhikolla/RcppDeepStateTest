function (xs, ys, n_pts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatializeArrayToLong"]][[length(e[["spatializeArrayToLong"]]) + 
        1]] <- list(xs = xs, ys = ys, n_pts = n_pts)
    .Call("_mousetrap_spatializeArrayToLong", xs, ys, n_pts)
}
