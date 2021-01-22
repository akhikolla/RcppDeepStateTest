function (actual, predicted, cutoff, beta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fScore_"]][[length(e[["fScore_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff, beta = beta)
    .Call("_ModelMetrics_fScore_", PACKAGE = "ModelMetrics", 
        actual, predicted, cutoff, beta)
}
