function (like) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_irt_classify_individuals"]][[length(e[["cdm_rcpp_irt_classify_individuals"]]) + 
        1]] <- list(like = like)
    .Call("_CDM_cdm_rcpp_irt_classify_individuals", PACKAGE = "CDM", 
        like)
}
