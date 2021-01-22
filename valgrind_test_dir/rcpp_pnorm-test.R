function (a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_pnorm"]][[length(e[["rcpp_pnorm"]]) + 1]] <- list(a = a)
    .Call("_NHMM_rcpp_pnorm", a)
}
