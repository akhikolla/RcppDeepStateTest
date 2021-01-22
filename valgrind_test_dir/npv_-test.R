function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["npv_"]][[length(e[["npv_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_npv_", PACKAGE = "ModelMetrics", actual, 
        predicted, cutoff)
}
