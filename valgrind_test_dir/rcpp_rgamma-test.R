function (a, b, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rgamma"]][[length(e[["rcpp_rgamma"]]) + 1]] <- list(a = a, 
        b = b, c = c)
    .Call("_NHMM_rcpp_rgamma", a, b, c)
}
