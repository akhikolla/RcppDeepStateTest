function (particles, log_weights) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedMean"]][[length(e[["weightedMean"]]) + 1]] <- list(particles = particles, 
        log_weights = log_weights)
    .Call("_serrsBayes_weightedMean", PACKAGE = "serrsBayes", 
        particles, log_weights)
}
