function (c, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dot"]][[length(e[["rcpp_dot"]]) + 1]] <- list(c = c, 
        d = d)
    .Call("_NHMM_rcpp_dot", c, d)
}
