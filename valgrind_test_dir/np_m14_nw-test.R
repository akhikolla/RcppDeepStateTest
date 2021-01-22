function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m14_nw"]][[length(e[["np_m14_nw"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m14_nw", PACKAGE = "bmotif", NZ, NP, W)
}
