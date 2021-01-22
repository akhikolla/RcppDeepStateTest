function (tt1, tt2, tt3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vusC_full_core"]][[length(e[["vusC_full_core"]]) + 1]] <- list(tt1 = tt1, 
        tt2 = tt2, tt3 = tt3)
    .Call("_bcROCsurface_vusC_full_core", tt1, tt2, tt3)
}
