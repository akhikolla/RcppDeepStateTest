function (file) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_AllPairsQuartetAgreement"]][[length(e[["tqdist_AllPairsQuartetAgreement"]]) + 
        1]] <- list(file = file)
    .Call("_Quartet_tqdist_AllPairsQuartetAgreement", file)
}
