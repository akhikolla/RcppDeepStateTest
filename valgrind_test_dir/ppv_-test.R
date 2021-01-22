function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ppv_"]][[length(e[["ppv_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_ppv_", PACKAGE = "ModelMetrics", actual, 
        predicted, cutoff)
}
