function (x, nbin, min, max) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cbin_alloc"]][[length(e[["cbin_alloc"]]) + 1]] <- list(x = x, 
        nbin = nbin, min = min, max = max)
    .Call("_FKSUM_cbin_alloc", x, nbin, min, max)
}
