function (fam, K, mixes, delt, y, ppp, theta1, theta2, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getvvv"]][[length(e[["rcpp_getvvv"]]) + 1]] <- list(fam = fam, 
        K = K, mixes = mixes, delt = delt, y = y, ppp = ppp, 
        theta1 = theta1, theta2 = theta2, z = z)
    .Call("_NHMM_rcpp_getvvv", fam, K, mixes, delt, y, ppp, theta1, 
        theta2, z)
}
