function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["msle_"]][[length(e[["msle_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_msle_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
