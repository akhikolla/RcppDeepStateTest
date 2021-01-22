function (population) 
{
    e <- get("data.env", .GlobalEnv)
    e[["integerise"]][[length(e[["integerise"]]) + 1]] <- list(population = population)
    .Call("_humanleague_integerise", PACKAGE = "humanleague", 
        population)
}
