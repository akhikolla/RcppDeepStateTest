function (qmatrix, skillspace) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_ideal_resp_pattern"]][[length(e[["cdm_rcpp_ideal_resp_pattern"]]) + 
        1]] <- list(qmatrix = qmatrix, skillspace = skillspace)
    .Call("_CDM_cdm_rcpp_ideal_resp_pattern", PACKAGE = "CDM", 
        qmatrix, skillspace)
}
