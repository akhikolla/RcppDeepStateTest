function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rpois"]][[length(e[["rcpp_rpois"]]) + 1]] <- list(a = a, 
        b = b)
    .Call("_NHMM_rcpp_rpois", a, b)
}
