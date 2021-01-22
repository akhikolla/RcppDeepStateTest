function (A, Wbin, psi, gamy, fam, K, mixes, delt, y, ppp, theta1, 
    theta2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getdenzity"]][[length(e[["rcpp_getdenzity"]]) + 
        1]] <- list(A = A, Wbin = Wbin, psi = psi, gamy = gamy, 
        fam = fam, K = K, mixes = mixes, delt = delt, y = y, 
        ppp = ppp, theta1 = theta1, theta2 = theta2)
    .Call("_NHMM_rcpp_getdenzity", A, Wbin, psi, gamy, fam, K, 
        mixes, delt, y, ppp, theta1, theta2)
}
