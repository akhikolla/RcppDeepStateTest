function (setLength, baserate, kappaMin, kappaMax, minPrecision = 0, 
    maxPrecision = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["random_contingency_table"]][[length(e[["random_contingency_table"]]) + 
        1]] <- list(setLength = setLength, baserate = baserate, 
        kappaMin = kappaMin, kappaMax = kappaMax, minPrecision = minPrecision, 
        maxPrecision = maxPrecision)
    .Call("_rhoR_random_contingency_table", PACKAGE = "rhoR", 
        setLength, baserate, kappaMin, kappaMax, minPrecision, 
        maxPrecision)
}
