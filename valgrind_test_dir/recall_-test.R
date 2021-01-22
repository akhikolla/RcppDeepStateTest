function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["recall_"]][[length(e[["recall_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_recall_", PACKAGE = "ModelMetrics", 
        actual, predicted, cutoff)
}
