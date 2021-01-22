function (pjk, sc) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_kli_id"]][[length(e[["cdm_rcpp_kli_id"]]) + 
        1]] <- list(pjk = pjk, sc = sc)
    .Call("_CDM_cdm_rcpp_kli_id", PACKAGE = "CDM", pjk, sc)
}
