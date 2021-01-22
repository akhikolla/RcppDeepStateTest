function (rank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CayleyNeighbour"]][[length(e[["CayleyNeighbour"]]) + 
        1]] <- list(rank = rank)
    .Call("_rankdist_CayleyNeighbour", rank)
}
