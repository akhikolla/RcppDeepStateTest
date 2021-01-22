function (XdesM, dimXdes, Xlambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_slca_calc_probs"]][[length(e[["cdm_rcpp_slca_calc_probs"]]) + 
        1]] <- list(XdesM = XdesM, dimXdes = dimXdes, Xlambda = Xlambda)
    .Call("_CDM_cdm_rcpp_slca_calc_probs", PACKAGE = "CDM", XdesM, 
        dimXdes, Xlambda)
}
