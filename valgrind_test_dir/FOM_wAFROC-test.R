function (nl, ll, n_lesions_per_image, max_cases, max_nl, max_ll, 
    weights) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FOM_wAFROC"]][[length(e[["FOM_wAFROC"]]) + 1]] <- list(nl = nl, 
        ll = ll, n_lesions_per_image = n_lesions_per_image, max_cases = max_cases, 
        max_nl = max_nl, max_ll = max_ll, weights = weights)
    .Call("_RJafroc_FOM_wAFROC", PACKAGE = "RJafroc", nl, ll, 
        n_lesions_per_image, max_cases, max_nl, max_ll, weights)
}
