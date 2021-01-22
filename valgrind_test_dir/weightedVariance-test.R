function (particles, log_weights, mean) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedVariance"]][[length(e[["weightedVariance"]]) + 
        1]] <- list(particles = particles, log_weights = log_weights, 
        mean = mean)
    .Call("_serrsBayes_weightedVariance", PACKAGE = "serrsBayes", 
        particles, log_weights, mean)
}
