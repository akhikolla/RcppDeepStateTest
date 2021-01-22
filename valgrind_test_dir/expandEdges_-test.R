function (eExp, center, res) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expandEdges_"]][[length(e[["expandEdges_"]]) + 1]] <- list(eExp = eExp, 
        center = center, res = res)
    .Call("_icosa_expandEdges_", eExp, center, res)
}
