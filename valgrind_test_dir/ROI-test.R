function (ncases_nor, ncases_abn, max_nl, n_les, nl, ll) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ROI"]][[length(e[["ROI"]]) + 1]] <- list(ncases_nor = ncases_nor, 
        ncases_abn = ncases_abn, max_nl = max_nl, n_les = n_les, 
        nl = nl, ll = ll)
    .Call("_RJafroc_ROI", PACKAGE = "RJafroc", ncases_nor, ncases_abn, 
        max_nl, n_les, nl, ll)
}
