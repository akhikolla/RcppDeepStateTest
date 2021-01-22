function (k1, k2, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_vmsin"]][[length(e[["const_vmsin"]]) + 1]] <- list(k1 = k1, 
        k2 = k2, lambda = lambda)
    .Call("_BAMBI_const_vmsin", k1, k2, lambda)
}
