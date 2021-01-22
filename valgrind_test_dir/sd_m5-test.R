function (NZ, NP, W, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sd_m5"]][[length(e[["sd_m5"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W, m = m)
    .Call("_bmotif_sd_m5", PACKAGE = "bmotif", NZ, NP, W, m)
}
