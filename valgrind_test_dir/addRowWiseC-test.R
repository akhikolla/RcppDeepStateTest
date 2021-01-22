function (WeightVectors, DataPoint) 
{
    e <- get("data.env", .GlobalEnv)
    e[["addRowWiseC"]][[length(e[["addRowWiseC"]]) + 1]] <- list(WeightVectors = WeightVectors, 
        DataPoint = DataPoint)
    .Call("_Umatrix_addRowWiseC", WeightVectors, DataPoint)
}
