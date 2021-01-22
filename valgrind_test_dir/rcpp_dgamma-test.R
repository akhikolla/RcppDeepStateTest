function (a, b, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dgamma"]][[length(e[["rcpp_dgamma"]]) + 1]] <- list(a = a, 
        b = b, c = c)
    .Call("_NHMM_rcpp_dgamma", a, b, c)
}
