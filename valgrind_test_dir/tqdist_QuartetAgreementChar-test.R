function (string1, string2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_QuartetAgreementChar"]][[length(e[["tqdist_QuartetAgreementChar"]]) + 
        1]] <- list(string1 = string1, string2 = string2)
    .Call("_Quartet_tqdist_QuartetAgreementChar", string1, string2)
}
