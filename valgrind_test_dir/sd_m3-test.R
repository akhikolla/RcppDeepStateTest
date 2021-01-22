function (NZ, NP, W, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sd_m3"]][[length(e[["sd_m3"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W, m = m)
    .Call("_bmotif_sd_m3", PACKAGE = "bmotif", NZ, NP, W, m)
}
