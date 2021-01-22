function (discrim_item_attribute) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_discrimination_index_test_level"]][[length(e[["cdm_rcpp_discrimination_index_test_level"]]) + 
        1]] <- list(discrim_item_attribute = discrim_item_attribute)
    .Call("_CDM_cdm_rcpp_discrimination_index_test_level", PACKAGE = "CDM", 
        discrim_item_attribute)
}
