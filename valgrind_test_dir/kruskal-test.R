function (W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kruskal"]][[length(e[["kruskal"]]) + 1]] <- list(W = W)
    .Call("_BNSL_kruskal", W)
}
