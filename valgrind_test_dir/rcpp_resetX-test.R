function (XXf, zbinf) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_resetX"]][[length(e[["rcpp_resetX"]]) + 1]] <- list(XXf = XXf, 
        zbinf = zbinf)
    .Call("_NHMM_rcpp_resetX", XXf, zbinf)
}
