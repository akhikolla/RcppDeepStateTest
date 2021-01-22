function (file1, file2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_QuartetAgreement"]][[length(e[["tqdist_QuartetAgreement"]]) + 
        1]] <- list(file1 = file1, file2 = file2)
    .Call("_Quartet_tqdist_QuartetAgreement", file1, file2)
}
