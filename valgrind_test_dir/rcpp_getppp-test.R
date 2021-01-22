function (gamy, mus) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getppp"]][[length(e[["rcpp_getppp"]]) + 1]] <- list(gamy = gamy, 
        mus = mus)
    .Call("_NHMM_rcpp_getppp", gamy, mus)
}
