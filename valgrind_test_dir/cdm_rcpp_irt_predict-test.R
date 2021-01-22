function (resp, irf1, K, TP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_irt_predict"]][[length(e[["cdm_rcpp_irt_predict"]]) + 
        1]] <- list(resp = resp, irf1 = irf1, K = K, TP = TP)
    .Call("_CDM_cdm_rcpp_irt_predict", PACKAGE = "CDM", resp, 
        irf1, K, TP)
}
