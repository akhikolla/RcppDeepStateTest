function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m16_py"]][[length(e[["np_m16_py"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m16_py", PACKAGE = "bmotif", NZ, NP, W)
}
