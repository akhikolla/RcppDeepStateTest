function (tree, trees) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tqdist_OneToManyQuartetAgreementChar"]][[length(e[["tqdist_OneToManyQuartetAgreementChar"]]) + 
        1]] <- list(tree = tree, trees = trees)
    .Call("_Quartet_tqdist_OneToManyQuartetAgreementChar", tree, 
        trees)
}
