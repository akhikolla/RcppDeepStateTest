function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_summ"]][[length(e[["rcpp_summ"]]) + 1]] <- list(A = A)
    .Call("_NHMM_rcpp_summ", A)
}
