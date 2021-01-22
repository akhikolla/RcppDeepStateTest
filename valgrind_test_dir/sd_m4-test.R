function (NZ, NP, W, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sd_m4"]][[length(e[["sd_m4"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W, m = m)
    .Call("_bmotif_sd_m4", PACKAGE = "bmotif", NZ, NP, W, m)
}
