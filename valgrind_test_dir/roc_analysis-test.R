function (pred, true_class) 
{
    e <- get("data.env", .GlobalEnv)
    e[["roc_analysis"]][[length(e[["roc_analysis"]]) + 1]] <- list(pred = pred, 
        true_class = true_class)
    .Call("_fbroc_roc_analysis", PACKAGE = "fbroc", pred, true_class)
}
