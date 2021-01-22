function (probs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rmultinom"]][[length(e[["rcpp_rmultinom"]]) + 1]] <- list(probs = probs)
    .Call("_NHMM_rcpp_rmultinom", probs)
}
