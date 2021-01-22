function (k, j, c, seq, M, csim) 
{
    e <- get("data.env", .GlobalEnv)
    e[["icor"]][[length(e[["icor"]]) + 1]] <- list(k = k, j = j, 
        c = c, seq = seq, M = M, csim = csim)
    .Call("_segmenTier_icor", PACKAGE = "segmenTier", k, j, c, 
        seq, M, csim)
}
