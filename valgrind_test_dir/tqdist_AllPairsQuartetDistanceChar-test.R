function (string) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_AllPairsQuartetDistanceChar"]][[length(e[["tqdist_AllPairsQuartetDistanceChar"]]) + 
        1]] <- list(string = string)
    .Call("_Quartet_tqdist_AllPairsQuartetDistanceChar", string)
}
