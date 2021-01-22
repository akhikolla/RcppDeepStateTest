function (A, Wbin, psi, K, y, thetainv, detS) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getdenzityMVN"]][[length(e[["rcpp_getdenzityMVN"]]) + 
        1]] <- list(A = A, Wbin = Wbin, psi = psi, K = K, y = y, 
        thetainv = thetainv, detS = detS)
    .Call("_NHMM_rcpp_getdenzityMVN", A, Wbin, psi, K, y, thetainv, 
        detS)
}
