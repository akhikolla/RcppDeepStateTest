function (data, dataresp, idealresp, theta, a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_generalized_distance_method"]][[length(e[["cdm_rcpp_generalized_distance_method"]]) + 
        1]] <- list(data = data, dataresp = dataresp, idealresp = idealresp, 
        theta = theta, a = a, b = b)
    .Call("_CDM_cdm_rcpp_generalized_distance_method", PACKAGE = "CDM", 
        data, dataresp, idealresp, theta, a, b)
}
