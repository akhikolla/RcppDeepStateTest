function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["nearestNeighbours"]][[length(e[["nearestNeighbours"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
