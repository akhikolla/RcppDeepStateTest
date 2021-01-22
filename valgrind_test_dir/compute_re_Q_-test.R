function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["compute_re_Q_"]][[length(e[["compute_re_Q_"]]) + 1]] <- list()
    list(NULL, character(0))
}
