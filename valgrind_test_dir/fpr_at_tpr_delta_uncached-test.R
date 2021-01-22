function (pred1, pred2, true_class, n_boot, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fpr_at_tpr_delta_uncached"]][[length(e[["fpr_at_tpr_delta_uncached"]]) + 
        1]] <- list(pred1 = pred1, pred2 = pred2, true_class = true_class, 
        n_boot = n_boot, n_steps = n_steps)
    .Call("_fbroc_fpr_at_tpr_delta_uncached", PACKAGE = "fbroc", 
        pred1, pred2, true_class, n_boot, n_steps)
}
