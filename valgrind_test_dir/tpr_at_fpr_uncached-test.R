function (pred, true_class, n_boot, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tpr_at_fpr_uncached"]][[length(e[["tpr_at_fpr_uncached"]]) + 
        1]] <- list(pred = pred, true_class = true_class, n_boot = n_boot, 
        n_steps = n_steps)
    .Call("_fbroc_tpr_at_fpr_uncached", PACKAGE = "fbroc", pred, 
        true_class, n_boot, n_steps)
}
