function (ptrs, inds, vals) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ic0"]][[length(e[["ic0"]]) + 1]] <- list(ptrs = ptrs, 
        inds = inds, vals = vals)
    .Call("_GPvecchia_ic0", PACKAGE = "GPvecchia", ptrs, inds, 
        vals)
}
