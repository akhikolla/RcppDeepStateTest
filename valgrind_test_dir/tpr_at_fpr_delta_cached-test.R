function (tpr1, fpr1, tpr2, fpr2, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tpr_at_fpr_delta_cached"]][[length(e[["tpr_at_fpr_delta_cached"]]) + 
        1]] <- list(tpr1 = tpr1, fpr1 = fpr1, tpr2 = tpr2, fpr2 = fpr2, 
        n_steps = n_steps)
    .Call("_fbroc_tpr_at_fpr_delta_cached", PACKAGE = "fbroc", 
        tpr1, fpr1, tpr2, fpr2, n_steps)
}
