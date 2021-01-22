function (xs, pos) 
{
    e <- get("data.env", .GlobalEnv)
    e[["takefirst"]][[length(e[["takefirst"]]) + 1]] <- list(xs = xs, 
        pos = pos)
    .Call("_BiDAG_takefirst", xs, pos)
}
