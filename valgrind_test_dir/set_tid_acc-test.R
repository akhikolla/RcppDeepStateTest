function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_tid_acc"]][[length(e[["set_tid_acc"]]) + 1]] <- list()
    list(NULL, character(0))
}
