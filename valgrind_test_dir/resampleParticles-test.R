function (log_weights, ampMx, scaleMx, peaks, baselines, n_y, 
    nwl) 
{
    e <- get("data.env", .GlobalEnv)
    e[["resampleParticles"]][[length(e[["resampleParticles"]]) + 
        1]] <- list(log_weights = log_weights, ampMx = ampMx, 
        scaleMx = scaleMx, peaks = peaks, baselines = baselines, 
        n_y = n_y, nwl = nwl)
    .Call("_serrsBayes_resampleParticles", PACKAGE = "serrsBayes", 
        log_weights, ampMx, scaleMx, peaks, baselines, n_y, nwl)
}
