function (sparseRatingMat, learningRate, regCoef, nrfeat, steps, 
    nr_users, nr_items, globalbaseline) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FSVDupdaterSparseMatBiases"]][[length(e[["FSVDupdaterSparseMatBiases"]]) + 
        1]] <- list(sparseRatingMat = sparseRatingMat, learningRate = learningRate, 
        regCoef = regCoef, nrfeat = nrfeat, steps = steps, nr_users = nr_users, 
        nr_items = nr_items, globalbaseline = globalbaseline)
    .Call("_rrecsys_FSVDupdaterSparseMatBiases", PACKAGE = "rrecsys", 
        sparseRatingMat, learningRate, regCoef, nrfeat, steps, 
        nr_users, nr_items, globalbaseline)
}
