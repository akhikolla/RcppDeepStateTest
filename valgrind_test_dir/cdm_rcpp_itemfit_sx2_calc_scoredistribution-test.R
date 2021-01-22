function (P1, Q1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_itemfit_sx2_calc_scoredistribution"]][[length(e[["cdm_rcpp_itemfit_sx2_calc_scoredistribution"]]) + 
        1]] <- list(P1 = P1, Q1 = Q1)
    .Call("_CDM_cdm_rcpp_itemfit_sx2_calc_scoredistribution", 
        PACKAGE = "CDM", P1, Q1)
}
