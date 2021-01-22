function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mse_"]][[length(e[["mse_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_mse_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
