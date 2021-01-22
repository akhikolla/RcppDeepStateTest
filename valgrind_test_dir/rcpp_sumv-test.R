function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_sumv"]][[length(e[["rcpp_sumv"]]) + 1]] <- list(A = A)
    .Call("_NHMM_rcpp_sumv", A)
}
