function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m7_c"]][[length(e[["np_m7_c"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m7_c", PACKAGE = "bmotif", NZ, NP, W)
}
