function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m13_nw"]][[length(e[["np_m13_nw"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m13_nw", PACKAGE = "bmotif", NZ, NP, W)
}
