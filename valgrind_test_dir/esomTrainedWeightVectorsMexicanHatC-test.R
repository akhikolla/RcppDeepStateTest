function (WeightVectors, DataPoint, indices, DistancesToBm, Radius, 
    LearningRate) 
{
    e <- get("data.env", .GlobalEnv)
    e[["esomTrainedWeightVectorsMexicanHatC"]][[length(e[["esomTrainedWeightVectorsMexicanHatC"]]) + 
        1]] <- list(WeightVectors = WeightVectors, DataPoint = DataPoint, 
        indices = indices, DistancesToBm = DistancesToBm, Radius = Radius, 
        LearningRate = LearningRate)
    invisible(c(".Call", "'_Umatrix_esomTrainedWeightVectorsMexicanHatC`", 
    "WeightVectors", "DataPoint", "indices", "DistancesToBm", 
    "Radius", "LearningRate"))
}
