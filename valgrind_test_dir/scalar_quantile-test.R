function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["scalar_quantile"]][[length(e[["scalar_quantile"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
