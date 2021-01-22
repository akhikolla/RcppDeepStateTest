function (V, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["indexToCoord"]][[length(e[["indexToCoord"]]) + 1]] <- list(V = V, 
        N = N)
    .Call("_propr_indexToCoord", V, N)
}
