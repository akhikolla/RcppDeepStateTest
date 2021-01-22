function (k, j, c, seq, M, csim) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ccor"]][[length(e[["ccor"]]) + 1]] <- list(k = k, j = j, 
        c = c, seq = seq, M = M, csim = csim)
    .Call("_segmenTier_ccor", PACKAGE = "segmenTier", k, j, c, 
        seq, M, csim)
}
