function (X_, labels_, nbClust, l, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcppDiscriminantAnalysisGlasso"]][[length(e[["rcppDiscriminantAnalysisGlasso"]]) + 
        1]] <- list(X_ = X_, labels_ = labels_, nbClust = nbClust, 
        l = l, r = r)
    .Call("_SelvarMix_rcppDiscriminantAnalysisGlasso", PACKAGE = "SelvarMix", 
        X_, labels_, nbClust, l, r)
}
