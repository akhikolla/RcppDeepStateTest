function (WeightVectors, DataPoint, indices, DistancesToBm, Radius, 
    LearningRate) 
{
    e <- get("data.env", .GlobalEnv)
    e[["esomTrainedWeightVectorsGaussC"]][[length(e[["esomTrainedWeightVectorsGaussC"]]) + 
        1]] <- list(WeightVectors = WeightVectors, DataPoint = DataPoint, 
        indices = indices, DistancesToBm = DistancesToBm, Radius = Radius, 
        LearningRate = LearningRate)
    invisible(c(".Call", "'_Umatrix_esomTrainedWeightVectorsGaussC`", 
    "WeightVectors", "DataPoint", "indices", "DistancesToBm", 
    "Radius", "LearningRate"))
}
