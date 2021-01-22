function (xs, ys, ts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["extractT"]][[length(e[["extractT"]]) + 1]] <- list(xs = xs, 
        ys = ys, ts = ts)
    .Call("_BiDAG_extractT", xs, ys, ts)
}
