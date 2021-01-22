function (spectra, peaks, baselines, i, start, sigma, old_weights, 
    alpha, idx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["reWeightParticles"]][[length(e[["reWeightParticles"]]) + 
        1]] <- list(spectra = spectra, peaks = peaks, baselines = baselines, 
        i = i, start = start, sigma = sigma, old_weights = old_weights, 
        alpha = alpha, idx = idx)
    .Call("_serrsBayes_reWeightParticles", PACKAGE = "serrsBayes", 
        spectra, peaks, baselines, i, start, sigma, old_weights, 
        alpha, idx)
}
