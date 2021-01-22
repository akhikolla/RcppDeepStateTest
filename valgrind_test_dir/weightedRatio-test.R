function (x, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedRatio"]][[length(e[["weightedRatio"]]) + 1]] <- list(x = x, 
        w = w)
    .Call("_surveysd_weightedRatio", PACKAGE = "surveysd", x, 
        w)
}
