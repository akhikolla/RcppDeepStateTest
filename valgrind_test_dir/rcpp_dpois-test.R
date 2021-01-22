function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dpois"]][[length(e[["rcpp_dpois"]]) + 1]] <- list(a = a, 
        b = b)
    .Call("_NHMM_rcpp_dpois", a, b)
}
