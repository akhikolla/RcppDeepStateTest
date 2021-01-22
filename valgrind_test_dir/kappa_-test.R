function (actual, predicted, cutoff) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kappa_"]][[length(e[["kappa_"]]) + 1]] <- list(actual = actual, 
        predicted = predicted, cutoff = cutoff)
    .Call("_ModelMetrics_kappa_", PACKAGE = "ModelMetrics", actual, 
        predicted, cutoff)
}
