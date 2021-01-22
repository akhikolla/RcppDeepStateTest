function (x, bounds, values) 
{
    e <- get("data.env", .GlobalEnv)
    e[["integrateStepFunc"]][[length(e[["integrateStepFunc"]]) + 
        1]] <- list(x = x, bounds = bounds, values = values)
    .Call("_starvz_integrateStepFunc", PACKAGE = "starvz", x, 
        bounds, values)
}
