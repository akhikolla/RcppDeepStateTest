function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mae_"]][[length(e[["mae_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_mae_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
