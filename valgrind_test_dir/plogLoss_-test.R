function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["plogLoss_"]][[length(e[["plogLoss_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_plogLoss_", PACKAGE = "ModelMetrics", 
        actual, predicted)
}
