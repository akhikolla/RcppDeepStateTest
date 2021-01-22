function (file) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_AllPairsQuartetDistance"]][[length(e[["tqdist_AllPairsQuartetDistance"]]) + 
        1]] <- list(file = file)
    .Call("_Quartet_tqdist_AllPairsQuartetDistance", file)
}
