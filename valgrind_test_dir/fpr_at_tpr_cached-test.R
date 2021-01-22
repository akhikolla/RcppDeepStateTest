function (tpr, fpr, n_steps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fpr_at_tpr_cached"]][[length(e[["fpr_at_tpr_cached"]]) + 
        1]] <- list(tpr = tpr, fpr = fpr, n_steps = n_steps)
    .Call("_fbroc_fpr_at_tpr_cached", PACKAGE = "fbroc", tpr, 
        fpr, n_steps)
}
