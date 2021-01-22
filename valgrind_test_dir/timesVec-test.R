function (aa, h, bb, q) 
{
    e <- get("data.env", .GlobalEnv)
    e[["timesVec"]][[length(e[["timesVec"]]) + 1]] <- list(aa = aa, 
        h = h, bb = bb, q = q)
    .Call("_NAM_timesVec", aa, h, bb, q)
}
