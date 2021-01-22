function (xs, ys, n, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["collectCcat"]][[length(e[["collectCcat"]]) + 1]] <- list(xs = xs, 
        ys = ys, n = n, m = m)
    .Call("_BiDAG_collectCcat", xs, ys, n, m)
}
