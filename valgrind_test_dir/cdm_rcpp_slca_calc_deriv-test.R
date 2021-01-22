function (XdesM, dimXdes, Xlambda, probs, nik, Nik) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_slca_calc_deriv"]][[length(e[["cdm_rcpp_slca_calc_deriv"]]) + 
        1]] <- list(XdesM = XdesM, dimXdes = dimXdes, Xlambda = Xlambda, 
        probs = probs, nik = nik, Nik = Nik)
    .Call("_CDM_cdm_rcpp_slca_calc_deriv", PACKAGE = "CDM", XdesM, 
        dimXdes, Xlambda, probs, nik, Nik)
}
