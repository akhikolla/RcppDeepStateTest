function (nTips) 
{
    e <- get("data.env", .GlobalEnv)
    e[["all_quartets"]][[length(e[["all_quartets"]]) + 1]] <- list(nTips = nTips)
    .Call("_Quartet_all_quartets", nTips)
}
