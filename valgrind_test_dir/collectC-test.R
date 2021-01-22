function (xs, ys, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["collectC"]][[length(e[["collectC"]]) + 1]] <- list(xs = xs, 
        ys = ys, n = n)
    .Call("_BiDAG_collectC", xs, ys, n)
}
