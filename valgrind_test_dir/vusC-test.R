function (tt, dd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vusC"]][[length(e[["vusC"]]) + 1]] <- list(tt = tt, dd = dd)
    .Call("_bcROCsurface_vusC", tt, dd)
}
