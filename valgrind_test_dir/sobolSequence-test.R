function (dim, n, skip = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sobolSequence"]][[length(e[["sobolSequence"]]) + 1]] <- list(dim = dim, 
        n = n, skip = skip)
    .Call("_humanleague_sobolSequence", PACKAGE = "humanleague", 
        dim, n, skip)
}
