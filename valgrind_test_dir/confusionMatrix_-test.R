function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["confusionMatrix_"]][[length(e[["confusionMatrix_"]]) + 
        1]] <- list(actual = actual, predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_confusionMatrix_", PACKAGE = "ModelMetrics", 
        actual, predicted, cutoff)
}
