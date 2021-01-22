function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m16_con"]][[length(e[["np_m16_con"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m16_con", PACKAGE = "bmotif", NZ, NP, W)
}
