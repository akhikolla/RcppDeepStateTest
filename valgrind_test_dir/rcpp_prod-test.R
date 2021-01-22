function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_prod"]][[length(e[["rcpp_prod"]]) + 1]] <- list(A = A)
    .Call("_NHMM_rcpp_prod", A)
}
