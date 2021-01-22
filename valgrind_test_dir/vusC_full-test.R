function (tt1, tt2, tt3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vusC_full"]][[length(e[["vusC_full"]]) + 1]] <- list(tt1 = tt1, 
        tt2 = tt2, tt3 = tt3)
    .Call("_bcROCsurface_vusC_full", tt1, tt2, tt3)
}
