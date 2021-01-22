function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rmse_"]][[length(e[["rmse_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_rmse_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
