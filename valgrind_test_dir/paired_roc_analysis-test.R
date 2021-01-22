function (pred1, pred2, true_class) 
{
    e <- get("data.env", .GlobalEnv)
    e[["paired_roc_analysis"]][[length(e[["paired_roc_analysis"]]) + 
        1]] <- list(pred1 = pred1, pred2 = pred2, true_class = true_class)
    .Call("_fbroc_paired_roc_analysis", PACKAGE = "fbroc", pred1, 
        pred2, true_class)
}
