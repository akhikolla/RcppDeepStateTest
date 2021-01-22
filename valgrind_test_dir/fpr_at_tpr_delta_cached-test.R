function (tpr1, fpr1, tpr2, fpr2, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fpr_at_tpr_delta_cached"]][[length(e[["fpr_at_tpr_delta_cached"]]) + 
        1]] <- list(tpr1 = tpr1, fpr1 = fpr1, tpr2 = tpr2, fpr2 = fpr2, 
        n_steps = n_steps)
    .Call("_fbroc_fpr_at_tpr_delta_cached", PACKAGE = "fbroc", 
        tpr1, fpr1, tpr2, fpr2, n_steps)
}
