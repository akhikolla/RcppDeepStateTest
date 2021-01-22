function (X, U) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_diag_XUtX"]][[length(e[["cpp_diag_XUtX"]]) + 1]] <- list(X = X, 
        U = U)
    .Call("_fixest_cpp_diag_XUtX", X, U)
}
