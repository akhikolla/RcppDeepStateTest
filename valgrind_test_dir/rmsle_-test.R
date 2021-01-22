function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rmsle_"]][[length(e[["rmsle_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_rmsle_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
