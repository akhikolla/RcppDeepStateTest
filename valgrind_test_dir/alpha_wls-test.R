function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_wls"]][[length(e[["alpha_wls"]]) + 1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_wls", PACKAGE = "ptsuite", dat)
}
