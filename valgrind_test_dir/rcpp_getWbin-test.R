function (z, K, J) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getWbin"]][[length(e[["rcpp_getWbin"]]) + 1]] <- list(z = z, 
        K = K, J = J)
    .Call("_NHMM_rcpp_getWbin", z, K, J)
}
