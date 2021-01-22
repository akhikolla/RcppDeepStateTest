function (log_weights) 
{
    e <- get("data.env", .GlobalEnv)
    e[["effectiveSampleSize"]][[length(e[["effectiveSampleSize"]]) + 
        1]] <- list(log_weights = log_weights)
    .Call("_serrsBayes_effectiveSampleSize", PACKAGE = "serrsBayes", 
        log_weights)
}
