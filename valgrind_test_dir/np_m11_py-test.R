function (NZ, NP, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["np_m11_py"]][[length(e[["np_m11_py"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W)
    .Call("_bmotif_np_m11_py", PACKAGE = "bmotif", NZ, NP, W)
}
