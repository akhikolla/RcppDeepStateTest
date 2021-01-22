function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ks_c_cdf_Rcpp"]][[length(e[["ks_c_cdf_Rcpp"]]) + 1]] <- list(n = n)
    .Call("_KSgeneral_ks_c_cdf_Rcpp", n)
}
