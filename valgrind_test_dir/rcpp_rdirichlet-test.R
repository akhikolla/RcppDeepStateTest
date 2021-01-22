function (B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rdirichlet"]][[length(e[["rcpp_rdirichlet"]]) + 
        1]] <- list(B = B)
    .Call("_NHMM_rcpp_rdirichlet", B)
}
