function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["pheno_ut"]][[length(e[["pheno_ut"]]) + 1]] <- list()
    list(NULL, character(0))
}
