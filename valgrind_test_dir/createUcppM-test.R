function (ptrs, inds, cov_vals) 
{
    e <- get("data.env", .GlobalEnv)
    e[["createUcppM"]][[length(e[["createUcppM"]]) + 1]] <- list(ptrs = ptrs, 
        inds = inds, cov_vals = cov_vals)
    .Call("_GPvecchia_createUcppM", PACKAGE = "GPvecchia", ptrs, 
        inds, cov_vals)
}
