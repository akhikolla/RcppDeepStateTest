function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m5_mw"]][[length(e[["np_m5_mw"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m5_mw", PACKAGE = "bmotif", NZ, NP, W)
}
