function (prob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ProbSampleReplace"]][[length(e[["ProbSampleReplace"]]) + 
        1]] <- list(prob = prob)
    .Call("_SpatialEpi_ProbSampleReplace", PACKAGE = "SpatialEpi", 
        prob)
}
