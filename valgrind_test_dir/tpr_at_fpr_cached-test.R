function (tpr, fpr, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tpr_at_fpr_cached"]][[length(e[["tpr_at_fpr_cached"]]) + 
        1]] <- list(tpr = tpr, fpr = fpr, n_steps = n_steps)
    .Call("_fbroc_tpr_at_fpr_cached", PACKAGE = "fbroc", tpr, 
        fpr, n_steps)
}
