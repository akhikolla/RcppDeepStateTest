function (rank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KendallNeighbour"]][[length(e[["KendallNeighbour"]]) + 
        1]] <- list(rank = rank)
    .Call("_rankdist_KendallNeighbour", rank)
}
