function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m16_mw"]][[length(e[["np_m16_mw"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m16_mw", PACKAGE = "bmotif", NZ, NP, W)
}
