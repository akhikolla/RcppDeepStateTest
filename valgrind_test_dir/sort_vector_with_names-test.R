function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sort_vector_with_names"]][[length(e[["sort_vector_with_names"]]) + 
        1]] <- list(x = x)
    .Call("_superml_sort_vector_with_names", PACKAGE = "superml", 
        x)
}
