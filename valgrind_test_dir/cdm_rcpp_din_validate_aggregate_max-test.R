function (IDI, itemindex, I) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_din_validate_aggregate_max"]][[length(e[["cdm_rcpp_din_validate_aggregate_max"]]) + 
        1]] <- list(IDI = IDI, itemindex = itemindex, I = I)
    .Call("_CDM_cdm_rcpp_din_validate_aggregate_max", PACKAGE = "CDM", 
        IDI, itemindex, I)
}
