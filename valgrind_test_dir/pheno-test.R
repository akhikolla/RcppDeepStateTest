function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["pheno"]][[length(e[["pheno"]]) + 1]] <- list()
    list(NULL, character(0))
}
