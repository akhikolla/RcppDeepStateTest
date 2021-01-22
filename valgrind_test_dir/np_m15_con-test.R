function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m15_con"]][[length(e[["np_m15_con"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m15_con", PACKAGE = "bmotif", NZ, NP, W)
}
