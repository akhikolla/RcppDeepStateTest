function (bp, bin_repr, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lossFunc"]][[length(e[["lossFunc"]]) + 1]] <- list(bp = bp, 
        bin_repr = bin_repr, z = z)
    .Call("_cort_lossFunc", bp, bin_repr, z)
}
