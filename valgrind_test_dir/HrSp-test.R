function (nl, ll, n_lesions_per_image, max_cases, max_nl, max_ll) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HrSp"]][[length(e[["HrSp"]]) + 1]] <- list(nl = nl, ll = ll, 
        n_lesions_per_image = n_lesions_per_image, max_cases = max_cases, 
        max_nl = max_nl, max_ll = max_ll)
    .Call("_RJafroc_HrSp", PACKAGE = "RJafroc", nl, ll, n_lesions_per_image, 
        max_cases, max_nl, max_ll)
}
