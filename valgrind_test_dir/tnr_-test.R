function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tnr_"]][[length(e[["tnr_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_tnr_", PACKAGE = "ModelMetrics", actual, 
        predicted, cutoff)
}
