function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["contigCells_cpp"]][[length(e[["contigCells_cpp"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
