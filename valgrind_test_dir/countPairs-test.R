function (classi1, classi2, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["countPairs"]][[length(e[["countPairs"]]) + 1]] <- list(classi1 = classi1, 
        classi2 = classi2, order = order)
    .Call("_aricode_countPairs", PACKAGE = "aricode", classi1, 
        classi2, order)
}
