function (probs, dim_probs, K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_discrimination_index_idi"]][[length(e[["cdm_rcpp_discrimination_index_idi"]]) + 
        1]] <- list(probs = probs, dim_probs = dim_probs, K = K)
    .Call("_CDM_cdm_rcpp_discrimination_index_idi", PACKAGE = "CDM", 
        probs, dim_probs, K)
}
