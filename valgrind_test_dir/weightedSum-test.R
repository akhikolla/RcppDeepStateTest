function (x, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedSum"]][[length(e[["weightedSum"]]) + 1]] <- list(x = x, 
        w = w)
    .Call("_surveysd_weightedSum", PACKAGE = "surveysd", x, w)
}
