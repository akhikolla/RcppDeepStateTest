function (pred1, pred2, true_class, n_boot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tpr_fpr_boot_paired"]][[length(e[["tpr_fpr_boot_paired"]]) + 
        1]] <- list(pred1 = pred1, pred2 = pred2, true_class = true_class, 
        n_boot = n_boot)
    .Call("_fbroc_tpr_fpr_boot_paired", PACKAGE = "fbroc", pred1, 
        pred2, true_class, n_boot)
}
