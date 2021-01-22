function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["logLoss_"]][[length(e[["logLoss_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_logLoss_", PACKAGE = "ModelMetrics", 
        actual, predicted)
}
