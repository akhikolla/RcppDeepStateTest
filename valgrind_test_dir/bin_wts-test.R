function (x, y, nbin, min, max) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bin_wts"]][[length(e[["bin_wts"]]) + 1]] <- list(x = x, 
        y = y, nbin = nbin, min = min, max = max)
    .Call("_FKSUM_bin_wts", x, y, nbin, min, max)
}
