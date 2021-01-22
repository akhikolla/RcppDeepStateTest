function (pred, true_class, n_boot, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fpr_at_tpr_uncached"]][[length(e[["fpr_at_tpr_uncached"]]) + 
        1]] <- list(pred = pred, true_class = true_class, n_boot = n_boot, 
        n_steps = n_steps)
    .Call("_fbroc_fpr_at_tpr_uncached", PACKAGE = "fbroc", pred, 
        true_class, n_boot, n_steps)
}
