function (param, ndays) 
{
    e <- get("data.env", .GlobalEnv)
    e[["simulateBS"]][[length(e[["simulateBS"]]) + 1]] <- list(param = param, 
        ndays = ndays)
    .Call("_pinbasic_simulateBS", PACKAGE = "pinbasic", param, 
        ndays)
}
