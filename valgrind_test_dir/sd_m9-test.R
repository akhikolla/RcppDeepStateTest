function (NZ, NP, W, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sd_m9"]][[length(e[["sd_m9"]]) + 1]] <- list(NZ = NZ, 
        NP = NP, W = W, m = m)
    .Call("_bmotif_sd_m9", PACKAGE = "bmotif", NZ, NP, W, m)
}
