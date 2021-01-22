function (pred, true_class, n_boot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tpr_fpr_boot"]][[length(e[["tpr_fpr_boot"]]) + 1]] <- list(pred = pred, 
        true_class = true_class, n_boot = n_boot)
    .Call("_fbroc_tpr_fpr_boot", PACKAGE = "fbroc", pred, true_class, 
        n_boot)
}
