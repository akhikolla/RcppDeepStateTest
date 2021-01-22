function (XDES, dimXdes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_slca_calc_Xdes"]][[length(e[["cdm_rcpp_slca_calc_Xdes"]]) + 
        1]] <- list(XDES = XDES, dimXdes = dimXdes)
    .Call("_CDM_cdm_rcpp_slca_calc_Xdes", PACKAGE = "CDM", XDES, 
        dimXdes)
}
