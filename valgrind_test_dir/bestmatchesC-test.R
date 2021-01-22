function (WeightVectors, DataPoints, Columns) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bestmatchesC"]][[length(e[["bestmatchesC"]]) + 1]] <- list(WeightVectors = WeightVectors, 
        DataPoints = DataPoints, Columns = Columns)
    .Call("_Umatrix_bestmatchesC", WeightVectors, DataPoints, 
        Columns)
}
