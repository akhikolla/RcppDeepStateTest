function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m11_con"]][[length(e[["np_m11_con"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m11_con", PACKAGE = "bmotif", NZ, NP, W)
}
