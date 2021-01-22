function (y, N, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pbinsumRow"]][[length(e[["pbinsumRow"]]) + 1]] <- list(y = y, 
        N = N, p = p)
    .Call("_nmixgof_pbinsumRow", PACKAGE = "nmixgof", y, N, p)
}
