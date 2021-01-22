function (beta, XX) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getNQQ"]][[length(e[["rcpp_getNQQ"]]) + 1]] <- list(beta = beta, 
        XX = XX)
    .Call("_NHMM_rcpp_getNQQ", beta, XX)
}
