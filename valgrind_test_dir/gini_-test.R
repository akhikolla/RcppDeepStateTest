function (actual) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gini_"]][[length(e[["gini_"]]) + 1]] <- list(actual = actual)
    .Call("_ModelMetrics_gini_", PACKAGE = "ModelMetrics", actual)
}
