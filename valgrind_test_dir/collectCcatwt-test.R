function (xs, ys, ws, n, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["collectCcatwt"]][[length(e[["collectCcatwt"]]) + 1]] <- list(xs = xs, 
        ys = ys, ws = ws, n = n, m = m)
    .Call("_BiDAG_collectCcatwt", xs, ys, ws, n, m)
}
