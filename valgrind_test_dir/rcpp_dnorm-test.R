function (a, b, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dnorm"]][[length(e[["rcpp_dnorm"]]) + 1]] <- list(a = a, 
        b = b, c = c)
    .Call("_NHMM_rcpp_dnorm", a, b, c)
}
