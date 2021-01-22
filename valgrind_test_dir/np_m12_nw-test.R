function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m12_nw"]][[length(e[["np_m12_nw"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m12_nw", PACKAGE = "bmotif", NZ, NP, W)
}
