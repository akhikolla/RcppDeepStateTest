function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_normalize_matrix_row"]][[length(e[["cdm_rcpp_normalize_matrix_row"]]) + 
        1]] <- list(x = x)
    .Call("_CDM_cdm_rcpp_normalize_matrix_row", PACKAGE = "CDM", 
        x)
}
