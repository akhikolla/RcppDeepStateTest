function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["basal_metabolic_pow"]][[length(e[["basal_metabolic_pow"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
