function (x, bandwidth, n, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gaussian_grammat_rcpp"]][[length(e[["gaussian_grammat_rcpp"]]) + 
        1]] <- list(x = x, bandwidth = bandwidth, n = n, d = d)
    .Call("_dHSIC_gaussian_grammat_rcpp", x, bandwidth, n, d)
}
