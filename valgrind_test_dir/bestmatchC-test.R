function (WeightVectors, DataPoint) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bestmatchC"]][[length(e[["bestmatchC"]]) + 1]] <- list(WeightVectors = WeightVectors, 
        DataPoint = DataPoint)
    .Call("_Umatrix_bestmatchC", WeightVectors, DataPoint)
}
