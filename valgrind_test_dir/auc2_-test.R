function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["auc2_"]][[length(e[["auc2_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_auc2_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
