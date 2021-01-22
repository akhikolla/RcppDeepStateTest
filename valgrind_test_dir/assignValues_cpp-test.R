function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["assignValues_cpp"]][[length(e[["assignValues_cpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
