function (attr_patt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_discrimination_index_attribute_patterns"]][[length(e[["cdm_rcpp_discrimination_index_attribute_patterns"]]) + 
        1]] <- list(attr_patt = attr_patt)
    .Call("_CDM_cdm_rcpp_discrimination_index_attribute_patterns", 
        PACKAGE = "CDM", attr_patt)
}
