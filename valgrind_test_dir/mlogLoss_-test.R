function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mlogLoss_"]][[length(e[["mlogLoss_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_mlogLoss_", PACKAGE = "ModelMetrics", 
        actual, predicted)
}
