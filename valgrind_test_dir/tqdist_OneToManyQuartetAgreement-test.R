function (file1, fileMany) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_OneToManyQuartetAgreement"]][[length(e[["tqdist_OneToManyQuartetAgreement"]]) + 
        1]] <- list(file1 = file1, fileMany = fileMany)
    .Call("_Quartet_tqdist_OneToManyQuartetAgreement", file1, 
        fileMany)
}
