function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["auc_"]][[length(e[["auc_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_auc_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
