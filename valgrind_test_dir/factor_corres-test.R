function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["factor_corres"]][[length(e[["factor_corres"]]) + 1]] <- list()
    list(NULL, character(0))
}
