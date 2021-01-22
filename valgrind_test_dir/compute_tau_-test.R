function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["compute_tau_"]][[length(e[["compute_tau_"]]) + 1]] <- list()
    list(NULL, character(0))
}
