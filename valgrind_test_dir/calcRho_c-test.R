function (x, OcSBaserate, testSetLength, testSetBaserateInflation = 0, 
    OcSLength = 10000L, replicates = 800L, ScSKappaThreshold = 0.9, 
    ScSKappaMin = 0.4, ScSPrecisionMin = 0.6, ScSPrecisionMax = 1, 
    KPs = matrix(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcRho_c"]][[length(e[["calcRho_c"]]) + 1]] <- list(x = x, 
        OcSBaserate = OcSBaserate, testSetLength = testSetLength, 
        testSetBaserateInflation = testSetBaserateInflation, 
        OcSLength = OcSLength, replicates = replicates, ScSKappaThreshold = ScSKappaThreshold, 
        ScSKappaMin = ScSKappaMin, ScSPrecisionMin = ScSPrecisionMin, 
        ScSPrecisionMax = ScSPrecisionMax, KPs = KPs)
    .Call("_rhoR_calcRho_c", PACKAGE = "rhoR", x, OcSBaserate, 
        testSetLength, testSetBaserateInflation, OcSLength, replicates, 
        ScSKappaThreshold, ScSKappaMin, ScSPrecisionMin, ScSPrecisionMax, 
        KPs)
}
