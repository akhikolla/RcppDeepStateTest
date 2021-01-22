function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedSlopeOneRM"]][[length(e[["weightedSlopeOneRM"]]) + 
        1]] <- list(x = x)
    .Call("_rrecsys_weightedSlopeOneRM", PACKAGE = "rrecsys", 
        x)
}
