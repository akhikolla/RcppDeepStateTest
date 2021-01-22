function (sparseRatingMat, learningRate, regCoef, nrfeat, steps, 
    nr_users, nr_items) 
{
    e <- get("data.env", .GlobalEnv)
    e[["FSVDupdaterSparseMat"]][[length(e[["FSVDupdaterSparseMat"]]) + 
        1]] <- list(sparseRatingMat = sparseRatingMat, learningRate = learningRate, 
        regCoef = regCoef, nrfeat = nrfeat, steps = steps, nr_users = nr_users, 
        nr_items = nr_items)
    .Call("_rrecsys_FSVDupdaterSparseMat", PACKAGE = "rrecsys", 
        sparseRatingMat, learningRate, regCoef, nrfeat, steps, 
        nr_users, nr_items)
}
