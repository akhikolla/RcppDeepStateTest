function (nSample, graph, thresholds, beta, responses) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IsingProcess"]][[length(e[["IsingProcess"]]) + 1]] <- list(nSample = nSample, 
        graph = graph, thresholds = thresholds, beta = beta, 
        responses = responses)
    .Call("_IsingSampler_IsingProcess", PACKAGE = "IsingSampler", 
        nSample, graph, thresholds, beta, responses)
}
