function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m12_py"]][[length(e[["np_m12_py"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m12_py", PACKAGE = "bmotif", NZ, NP, W)
}
