function (col, finsiz) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funX"]][[length(e[["funX"]]) + 1]] <- list(col = col, 
        finsiz = finsiz)
    .Call("_NAM_funX", col, finsiz)
}
