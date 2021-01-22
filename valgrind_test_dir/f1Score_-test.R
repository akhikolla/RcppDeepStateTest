function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["f1Score_"]][[length(e[["f1Score_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_f1Score_", PACKAGE = "ModelMetrics", 
        actual, predicted, cutoff)
}
