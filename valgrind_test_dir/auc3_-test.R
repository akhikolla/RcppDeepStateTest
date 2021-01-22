function (actual, predicted, ranks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["auc3_"]][[length(e[["auc3_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, ranks = ranks)
    .Call("_ModelMetrics_auc3_", PACKAGE = "ModelMetrics", actual, 
        predicted, ranks)
}
