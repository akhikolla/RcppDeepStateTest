function (a, b, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rnorm"]][[length(e[["rcpp_rnorm"]]) + 1]] <- list(a = a, 
        b = b, c = c)
    .Call("_NHMM_rcpp_rnorm", a, b, c)
}
