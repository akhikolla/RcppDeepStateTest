function (K, z, dirprior, subseqy) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getQQ"]][[length(e[["rcpp_getQQ"]]) + 1]] <- list(K = K, 
        z = z, dirprior = dirprior, subseqy = subseqy)
    .Call("_NHMM_rcpp_getQQ", K, z, dirprior, subseqy)
}
