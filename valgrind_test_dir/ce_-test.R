function (actual, predicted) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ce_"]][[length(e[["ce_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted)
    .Call("_ModelMetrics_ce_", PACKAGE = "ModelMetrics", actual, 
        predicted)
}
