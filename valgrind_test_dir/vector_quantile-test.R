function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["vector_quantile"]][[length(e[["vector_quantile"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
