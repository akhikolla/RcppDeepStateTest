function (string) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_AllPairsQuartetAgreementChar"]][[length(e[["tqdist_AllPairsQuartetAgreementChar"]]) + 
        1]] <- list(string = string)
    .Call("_Quartet_tqdist_AllPairsQuartetAgreementChar", string)
}
