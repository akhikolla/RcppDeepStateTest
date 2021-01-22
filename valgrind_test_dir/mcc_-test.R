function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mcc_"]][[length(e[["mcc_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_mcc_", PACKAGE = "ModelMetrics", actual, 
        predicted, cutoff)
}
