function (xs, pos, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["takelast"]][[length(e[["takelast"]]) + 1]] <- list(xs = xs, 
        pos = pos, n = n)
    .Call("_BiDAG_takelast", xs, pos, n)
}
