function (x, n, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["median_bandwidth_rcpp"]][[length(e[["median_bandwidth_rcpp"]]) + 
        1]] <- list(x = x, n = n, d = d)
    .Call("_dHSIC_median_bandwidth_rcpp", x, n, d)
}
