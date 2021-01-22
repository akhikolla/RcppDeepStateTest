function (tpr, fpr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["add_roc_points"]][[length(e[["add_roc_points"]]) + 1]] <- list(tpr = tpr, 
        fpr = fpr)
    .Call("_fbroc_add_roc_points", PACKAGE = "fbroc", tpr, fpr)
}
