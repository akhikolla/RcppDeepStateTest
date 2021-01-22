function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["brier_"]][[length(e[["brier_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_brier_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
