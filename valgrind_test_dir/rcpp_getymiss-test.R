function (fam, K, z, ppp, theta1, theta2, mixes, delt, J) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getymiss"]][[length(e[["rcpp_getymiss"]]) + 1]] <- list(fam = fam, 
        K = K, z = z, ppp = ppp, theta1 = theta1, theta2 = theta2, 
        mixes = mixes, delt = delt, J = J)
    .Call("_NHMM_rcpp_getymiss", fam, K, z, ppp, theta1, theta2, 
        mixes, delt, J)
}
