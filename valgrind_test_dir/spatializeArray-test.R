function (xs, ys, n_pts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatializeArray"]][[length(e[["spatializeArray"]]) + 
        1]] <- list(xs = xs, ys = ys, n_pts = n_pts)
    .Call("_mousetrap_spatializeArray", xs, ys, n_pts)
}
