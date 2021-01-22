function (pIn, pop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["prob2IntFreq"]][[length(e[["prob2IntFreq"]]) + 1]] <- list(pIn = pIn, 
        pop = pop)
    .Call("_humanleague_prob2IntFreq", PACKAGE = "humanleague", 
        pIn, pop)
}
