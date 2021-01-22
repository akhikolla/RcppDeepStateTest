function (idx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["idx_to_letter"]][[length(e[["idx_to_letter"]]) + 1]] <- list(idx = idx)
    .Call("_jmotif_idx_to_letter", PACKAGE = "jmotif", idx)
}
