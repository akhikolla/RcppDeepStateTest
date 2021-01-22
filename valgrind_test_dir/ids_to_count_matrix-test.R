function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["ids_to_count_matrix"]][[length(e[["ids_to_count_matrix"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
