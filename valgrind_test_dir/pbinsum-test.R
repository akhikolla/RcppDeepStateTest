function (y, N, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pbinsum"]][[length(e[["pbinsum"]]) + 1]] <- list(y = y, 
        N = N, p = p)
    .Call("_nmixgof_pbinsum", PACKAGE = "nmixgof", y, N, p)
}
