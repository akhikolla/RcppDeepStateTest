function (l, m, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_distance"]][[length(e[["rcpp_distance"]]) + 1]] <- list(l = l, 
        m = m, N = N)
    .Call("_FastGP_rcpp_distance", PACKAGE = "FastGP", l, m, 
        N)
}
